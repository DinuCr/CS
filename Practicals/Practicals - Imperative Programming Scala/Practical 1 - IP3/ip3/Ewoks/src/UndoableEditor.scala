

// UndoHistoryEditor.scala
// Copyright (c) 2015 J. M. Spivey
// Modified 2017 by P.G. Jeavons

import UndoHistory.Change

/** The controller class for an  editor with undoable commands */
class UndoableEditor extends Editor with UndoHistory {
    private var lastChange : Change = null

    /** Command: Insert a character and record change */
    override def insertCommand(ch: Char) {
        super.insertCommand(ch)
        lastChange = new AmalgInsertion(ed.point-1, ch)
    }

    /** Record of insertion that can be amalgamated with adjacent, similar changes */
    class AmalgInsertion(val pos: Int, ch: Char) extends Change {
        /** The text inserted by all commands that have merged with this one */
        private val text = new Text(ch)

        def undo() { ed.deleteRange(pos, text.length) }
        def redo() { ed.insert(pos, text) }

        override def amalgamate(change: Change) = {
            change match {
                case other: AmalgInsertion =>
                    if (text.charAt(text.length-1) == '\n'
                            || other.pos != this.pos + this.text.length)
                        false
                    else {
                        text.insert(text.length, other.text)
                        true
                    }

                case _ => false
            }
        }
    }


    /** Command: Delete in a specified direction and record change */
    override def deleteCommand(dir: Int): Boolean = {
        var p = ed.point
        var ch = ' '

        if (dir == Editor.LEFT) p -= 1;
        if (p>=0 && p<ed.length) ch = ed.charAt(p)

        if (super.deleteCommand(dir)) {
            lastChange = new Change {
                def undo() { ed.insert(p, ch) }
                def redo() { ed.deleteChar(p) }
            }
            return true
        }
        return false
    }

    override def transposeCommand() : Boolean =
    {
        var p = ed.point
        if(super.transposeCommand())
        {
            lastChange = new Change
            {
                def undo() =
                {
                    ed.point=p
                    ed.transpose()
                    ed.point-=1
                }
                def redo() =
                {
                  ed.point=p
                  ed.transpose()
                }
            }
            return true
        }
        return false
    }

    /** Prompt for a file to read into the buffer and reset history */
    override def replaceFileCommand(): Boolean = {
        if (super.replaceFileCommand()) {resetHistory(); return true}
        return false
    }


    // Command execution protocol

    /** Execute a command, and store all information necessary to undo it */
    override def obey(cmd: Editor.Command) {
        val before = ed.getState()
        super.obey(cmd)
        val after = ed.getState()
        if (lastChange != null) updateHistory(new EditorChange(before, lastChange, after))
        lastChange = null
     }

    /** Decorator for changes that preserves other state of the editor  */
    class EditorChange(private val before: ed.Memento,
         private val change: Change, private var after: ed.Memento) extends Change {

        def undo() { change.undo(); before.restore() }
        def redo() { change.redo(); after.restore() }

        override def amalgamate(other: Change) = {
            if (! change.amalgamate(other.asInstanceOf[EditorChange].change))
                false
            else {
                after = other.asInstanceOf[EditorChange].after
                true
            }
        }
    }

}

object UndoableEditor {
    /** Extend the keymap with undo and redo commands */
    Editor.keymap += Display.ctrl('Y') -> (_.asInstanceOf[UndoableEditor].redo)
    Editor.keymap += Display.ctrl('Z') -> (_.asInstanceOf[UndoableEditor].undo)

    /** Main program for the entire Ewoks (with undo) application. */
    def main(args: Array[String]) {
       // Check number of arguments
       if (args.length > 1) {
            Console.err.println("Usage: ewoks [file]")
            scala.sys.exit(2)
        }

        // Initial setup
        val terminal = new Terminal("EWOKS (with undo)")
        terminal.activate()
        val display = new Display(terminal)
        val app = new UndoableEditor()
        app.activate(display)
        if (args.length > 0) app.loadFile(args(0))

        // Main execution loop
        app.commandLoop()
        scala.sys.exit(0)
    }
}

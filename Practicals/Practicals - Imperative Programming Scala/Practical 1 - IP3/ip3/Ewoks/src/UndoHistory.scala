

// UndoHistory.scala
// Copyright (c) 2015 J. M. Spivey
// Modified 2017 by P.G. Jeavons 

/** A mixin that can record a history of undoable changes */
trait UndoHistory {
    /** A stack of undoable changes from executed actions. */
    private val history = new scala.collection.mutable.ArrayBuffer[UndoHistory.Change]

    /** Index into undo stack.  Elements history[0..u) have been executed
            but not undone, and elements history[u..) have been undone. */
    private var undoPointer = 0
       
    /** Beep on error. */
    def beep() // abstract

    /** Record undo info into history */
    def updateHistory(change: UndoHistory.Change) {
         if (change != null) {
            history.reduceToSize(undoPointer)

            if (history.size > 0) {
                val prev = history.last
                if (prev.amalgamate(change)) return
            }
            history.append(change); undoPointer += 1
        }
    }
    
    /** Reset the history, e.g. after loading a new file */
    def resetHistory() {
        history.clear(); undoPointer = 0
    }

    /** Undo the latest command. */
    def undo(): Boolean = { 
        if (undoPointer == 0) { beep(); return false}
        undoPointer -= 1
        val change = history(undoPointer)
        change.undo()
        return true
    }

    /** Redo the latest undone command. */
    def redo(): Boolean = {
        if (undoPointer == history.size) { beep(); return false }
        val change = history(undoPointer)
        undoPointer += 1
        change.redo()
        return true
    }

 
}

object UndoHistory {
    /** An element of the undo history. */
    abstract class Change {
        /** Reset the subject to its previous state. */
        def undo() // abstract

        /** Reset the subject to the state after the change. */
        def redo() // abstract

        /** Try to amalgamate this change with another. */
        def amalgamate(other: Change) = false
    }
}

import scala.swing._
import scala.swing.event._

object LayoutDemo extends SimpleSwingApplication {
     def top = new MainFrame {
         contents = new BoxPanel(Orientation.Horizontal) {
            val lab = new Label("First component - a label") 
                 { opaque = true; background = new Color(180,180,250) } 
            val b1 = new Button("Second component - a button") 
                 { background = new Color(0,250,0); override def toString() = "b1" }
            val b2 = new ToggleButton 
                 { minimumSize = new Dimension(100,20); override def toString() = "b2" }
            val tx = new TextArea("Fourth component - a text area") 
                 { lineWrap = true; 
                   listenTo(b1,b2); 
                   reactions += {case ButtonClicked(b) => text = "Button "+b+" clicked" }
                 }
            contents += (lab,b1,b2,tx)
        }
        title = "Layout Demo"
        location = new Point(200,400)
        size = new Dimension(500,100)       
    }
}

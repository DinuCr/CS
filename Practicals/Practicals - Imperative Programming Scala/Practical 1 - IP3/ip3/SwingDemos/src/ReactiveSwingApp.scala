import scala.swing._
import scala.swing.event._

object ReactiveSwingApp extends SimpleSwingApplication {

    def top = new MainFrame {
        title = "Reactive Swing App"

        val button = new Button {
            text = "Click me"
        }

        val label = new Label {
            text = "No button clicks registered"
        }       

        contents = new BoxPanel(Orientation.Vertical) {
            contents += button
            contents += label
            border = Swing.EmptyBorder(20, 20, 20, 20)
        }

        var nClicks = 0

        reactions += {
            case ButtonClicked(b) =>
                nClicks += 1
                label.text = "Number of button clicks: "+ nClicks
        }
    }
}    

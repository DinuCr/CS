import scala.swing._
import scala.swing.event._

object FirstSwingApp extends SimpleSwingApplication {
    def top = new MainFrame {
        contents = new Label("Hello world of GUI") 
        
        title = "First Swing App"
        location = new Point(200,400)
        size = new Dimension(500,100)

    }
}
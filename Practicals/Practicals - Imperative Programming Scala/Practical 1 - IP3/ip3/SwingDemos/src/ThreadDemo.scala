import scala.swing._

object ThreadDemo extends SimpleSwingApplication {
    def top = new MainFrame {
       val label = new Label{text="Thread Demo initialised"}
       contents = new BoxPanel(Orientation.Vertical) {
          contents += label
          border = Swing.EmptyBorder(20, 20, 20, 20)
       }

       val timer = new Thread {
           override def run {
               Thread.sleep(2000); Swing.onEDT(label.text="Timer is halfway")  
               Thread.sleep(2000); Swing.onEDT(label.text="Timer is done")  
           }
        }

        title = "Thread Demo"
        location = new Point(200,400)
        size = new Dimension(500,100)
        
        timer.start()   
    }
}
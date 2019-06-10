import scala.swing._
import scala.swing.event._
import scala.util.Random
import java.awt.Color

object DrawingDemo extends SimpleSwingApplication {
     def top = new MainFrame {
         contents = new Component {
            var x = 0
            override def paintComponent(g: Graphics2D) = {
                super.paintComponent(g)
                g.setColor(Color.getHSBColor(Random.nextFloat, 0.9f, 1.0f))
                g.fillOval(x, 20, 100, 30)
                g.setColor(new Color(0,0,0))
	              g.drawString("Paint at "+x, x+15, 40)
            }
            
            listenTo(mouse.clicks)
            reactions += {
                case e: MouseClicked => 
                    x = e.point.x
                    repaint
            }
        }

        title = "Drawing Demo"
        location = new Point(200,400)
        size = new Dimension(500,100)       
    }
}

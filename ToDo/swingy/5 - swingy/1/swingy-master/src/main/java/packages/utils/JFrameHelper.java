package packages.utils;

import java.awt.Image;
import java.io.File;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class JFrameHelper{
    public static void ShowErrorDialog(JFrame jFrame, String message){
        JOptionPane.showMessageDialog(jFrame, message, "Warning!", JOptionPane.WARNING_MESSAGE);
    }

    public static void ShowInfoDialog(JFrame jFrame, String title, String message){
        JOptionPane.showMessageDialog(jFrame, message, title, JOptionPane.INFORMATION_MESSAGE);
    }

    public static Boolean ShowConfirmDialog(JFrame jFrame, String title, String message){
        int response = JOptionPane.showConfirmDialog(jFrame, message, title, JOptionPane.YES_NO_OPTION);

        if (response == JOptionPane.YES_OPTION){
            return (true);
        }
        return (false);
    }

    public static JLabel getLabelImage(String imagePath, int imageSize)
    {
        try{
            ImageIcon imageIcon = new ImageIcon(ImageIO.read(new File(imagePath)));
            Image image = imageIcon.getImage();
            Image imageScaled = image.getScaledInstance(imageSize, imageSize, Image.SCALE_SMOOTH);
            JLabel lblImage = new JLabel();
            lblImage.setIcon(new ImageIcon(imageScaled));
            return (lblImage);
        }catch(Exception exc){
            System.err.println("Error Setting Image: " + exc.getMessage());
        }
        return (null);
    }
}


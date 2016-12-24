import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class TextEditor extends JFrame{
	String tempdisplay = "";
	
	public TextEditor(FileDescriptor info, TreeNode node){

		//this.getContentPane().setLayout(new FlowLayout());
		this.setSize(450, 300);
	
		JPanel text = new JPanel();
		text.setBackground(Color.WHITE);
		text.setLayout(new BorderLayout());
		text.setBounds(0,0, 450, 400);
		
		JTextArea textarea = new JTextArea(30,50);
		textarea.setText("");
		text.add(textarea);
		
		
		JPanel panel = new JPanel();
		Button b1 = new Button("Save");
		panel.setLayout(new BorderLayout());
		panel.add("South",b1);		
		
		
		
		panel.add(text, BorderLayout.NORTH);
		panel.add(textarea);
		add(panel);

		node.fileDescriptor.content= "";
		System.out.println("node content: "+ node.displayContent());
		
		if(node!=null){
			textarea.setText(node.fileDescriptor.getContent());
		}
		
		
		
		b1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				tempdisplay = textarea.getText();
				//textarea.setText(tempdisplay + "");
				
				node.fileDescriptor.appendContent(tempdisplay);
				System.out.println("node after save :" + node.displayContent());
			}
		});
		
		
		
		
	}
}

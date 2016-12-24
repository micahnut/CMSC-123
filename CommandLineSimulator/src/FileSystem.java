import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Dialog;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.util.*;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class FileSystem {

	Tree tree;
	TreeNode current;
	String[] arguments;
	String command;

	FileSystem() {
		TreeNode root = new TreeNode(new FileDescriptor("root", true), null);
		tree = new Tree(root);
		current = tree.root;
	}

	public static void main(String[] args) throws IOException, FileNotFoundException {
		FileSystem fs = new FileSystem();

		FileOutputStream fos = null;
		ObjectOutputStream oos = null;
		FileInputStream fis = null;
		ObjectInputStream ois = null;
				
		fs.readFile();
		fs.userInput();

	}

	public void readFile() {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("mp3.in"));

			String line;
			//int i = 1;
			while ((line = br.readLine()) != null) {
				//System.out.print((i++)+" ");
				parse(line);
				execute(command);

			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	public void writeFile(String line){
		BufferedWriter bw = null;
		
		
		try{
			File file = new File("mp3.out");
			
			if(!file.exists()){
				file.createNewFile();
			}
		
			FileWriter f = new FileWriter(file.getAbsoluteFile(),true);
			bw = new BufferedWriter(f);
			bw.write(line + "\n");
			bw.close();
		
		}catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e){
			e.printStackTrace();
		}
	}
	

	public void execute(String command) {

		//System.out.println("command:" + command);

		FileDescriptor info;
		TreeNode tmp_curr;
		
	
		String tmparg[];
		
		switch (command) {

		case "mkdir":
			//boolean exists;
			// search if the directory or folder exists
			if (arguments != null) {
				 tmparg = arguments[0].split("/");
				if(tmparg.length==1){
					String arg1 = arguments[0];
					//exists = false;
					for (int i = 0; i < current.children.size(); i++) {
						if (current.children.get(i).getFileName().equals(arg1)) {
							//System.out.println("found");
							System.out.println("mkdir:" +arg1+ ": Already exists");
							writeFile("mkdir:" +arg1+ ": Already exists");
						
						return;
						}

					}
				
				
				info = new FileDescriptor(arg1, true);
				tmp_curr = new TreeNode(info, current);

				} 
				else{
					
					boolean found;
					TreeNode curr = current;
					for(int i=0; i<(tmparg.length-1);i++){
						found = false;
						//wala nalagay sa code///
						if(tmparg[i].equals("..")){
							if(curr!=tree.root)
								curr = curr.parent;
						}
						
						//----------------------//
						//System.out.println(tmparg[i]);
						else{
							for(int j=0;j<curr.children.size();j++){
								if(curr.children.get(j).getFileName().equals(tmparg[i]) && curr.children.get(j).fileDescriptor.isDIR){
									curr = curr.children.get(j);
									found = true;
									break;
								}
							}
							if(!found){
								System.out.println("mkdir: Directory not found");
								writeFile("mkdir: Directory not found");
								//System.out.println("curr:"+ curr.getFileName());
								return;
							}
						}
					}
					info = new FileDescriptor(tmparg[tmparg.length-1], true);
					tmp_curr = new TreeNode(info, curr);
				}
				
				
			}	
				
			else {
				System.out.println("usage: mkdir <directory name>");
				writeFile("usage: mkdir <directory name>");
			}
		

			break;

		case "rmdir":
			
			if (arguments != null) {
				 tmparg = arguments[0].split("/");
				if(tmparg.length==1){
					String arg1 = arguments[0];
	
					for (int i = 0; i < current.children.size(); i++) {
						if (current.children.get(i).getFileName().equals(arg1)) {
							System.out.println("Directory: '" + current.children.get(i).getFileName() + "' deleted.");
							current.children.get(i).remove();
							return;
						}
	
					}
					System.out.println("rmdir: No such file or directory.");
					writeFile("rmdir: No such file or directory.");
				}
				else{
					boolean found;
					TreeNode curr = current;
					for(int i=0; i<tmparg.length;i++){
						found = false;
						//wala nalagay sa code///
						if(tmparg[i].equals("..")){
							if(curr!=tree.root)
								curr = curr.parent;
						}
						
						//----------------------//
						else{
							for(int j=0;j<curr.children.size();j++){
								if(curr.children.get(j).getFileName().equals(tmparg[i]) && curr.children.get(j).fileDescriptor.isDIR){
									curr = curr.children.get(j);
									found = true;
									break;
								}
							}
							
							if(!found){
								System.out.println("rmdir: Directory not found");
								writeFile("rmdir: Directory not found");
								return;
							}
						}
					}
					curr.remove();
				}
				
			} 
			else {
				System.out.println("usage: rmdir <directory name>");
				writeFile("usage: rmdir <directory name>");
			}
			break;

		case "cd":
			if (arguments != null) {
				String arr[] = arguments[0].split("/");
				boolean found;
				TreeNode tmpc = current;

				for (int i = 0; i < arr.length; i++) {
					found = false;
					if (arr[i].equals("..")) {
						if (tmpc != tree.root)
							tmpc = tmpc.parent;
					} else {
						for (int j = 0; j < tmpc.children.size(); j++) {
							if (tmpc.children.get(j).getFileName().equals(arr[i])) {
								tmpc = tmpc.children.get(j);
								found = true;
								break;
							}
						}

						if (!found) {
							// System.out.println(arr[i]);
							// System.out.println(current.children.size());
							// System.out.println(current.getFileName());
							System.out.println("cd: No such file or directory.");
							writeFile("cd: No such file or directory.");
							return;
						}
					}
				}
				
				current = tmpc;
			
			}else{
				System.out.println("usage: cd <directory name> or cd ..");
				writeFile("usage: cd <directory name> or cd ..");
			}
			
			break;

		case "ls":
			if (arguments == null) {

				for (int i = 0; i < current.children.size(); i++) {
					System.out.println(current.children.get(i).getFileName());
					writeFile(current.children.get(i).getFileName());
				}
			} else {
				String arg = arguments[0];

				if (arg.charAt(0) == '*' && arg.charAt(arg.length() - 1) == '*') {
					for (int i = 0; i < current.children.size(); i++) {
						if (current.children.get(i).getFileName().contains(arg.substring(1, arg.length() - 1))) {
							//System.out.println(arg.substring(1, arg.length() - 1));
							System.out.println(current.children.get(i).getFileName());
							writeFile(current.children.get(i).getFileName());
						}
					}
				}

				else if (arg.charAt(0) == '*') {
					for (int i = 0; i < current.children.size(); i++) {

						String tmp = current.children.get(i).getFileName().substring(
								current.children.get(i).getFileName().length() - (arg.length() - 1),
								current.children.get(i).getFileName().length());

						// System.out.println("tmp is:"+ tmp);
						if (arg.contains(tmp)) {
							System.out.println(current.children.get(i).getFileName());
							writeFile(current.children.get(i).getFileName());
						}
					}
				} else if (arg.charAt(arg.length() - 1) == '*') {
					for (int i = 0; i < current.children.size(); i++) {
						if(current.children.get(i).getFileName().length()>arg.length()-1){
							String tmp = current.children.get(i).getFileName().substring(0, arg.length() - 1);

							if (arg.contains(tmp)) {
								System.out.println(current.children.get(i).getFileName());
								writeFile(current.children.get(i).getFileName());
							}
						}
					}
				}

			}

			break;

		case "edit":
			// arg1 = arguments[0];
			// info = new FileDescriptor(arg1, false);
			// tmp_curr = new TreeNode(info, tree.current);
			//
			// tree.insert(tmp_curr);
			//
			// System.out.println("tmp curr content: "+
			// tmp_curr.displayContent());
			//
			// displayDialog(info, tmp_curr);

			if (arguments != null) {
				String arg1 = arguments[0];
				info = new FileDescriptor(arg1, false);

				Scanner sc = new Scanner(System.in);
				info.content = "";
				info.content += sc.nextLine();
				TreeNode node = null;

				for (int i = 0; i < current.children.size(); i++) {
					if (current.children.get(i).getFileName().equals(arg1)) {
						node = current.children.get(i);

					}
				}
				if (node == null) {
					node = new TreeNode(info, current); // create new
//					System.out.println("HERE");
//					System.out.println(current.children.size());

				} else {
					node.fileDescriptor.content += " ";
					node.fileDescriptor.content += info.content; // replace
																	// texts
				}

			} else {
				System.out.println("usage: edit <filename>");
				writeFile("usage: edit <filename>");
			}

			break;
		case "show":
			if (arguments != null) {
				String arg1 = arguments[0];
				for (int i = 0; i < current.children.size(); i++) {
					if (current.children.get(i).getFileName().equals(arg1)
							&& !current.children.get(i).fileDescriptor.isDIR) {
						System.out.println(current.children.get(i).displayContent());
						writeFile(current.children.get(i).displayContent());
					}
				}
			}
			else{
				System.out.println("usage: show <filename>");
				writeFile("usage: show <filename>");
			}
			break;
		case "rm":

			if (arguments != null) {
				String arg1 = arguments[0];

				for (int i = 0; i < current.children.size(); i++) {
					if (current.children.get(i).getFileName().equals(arg1) && !current.children.get(i).fileDescriptor.isDIR) {
						System.out.println("File: '" + current.children.get(i).getFileName() + "' deleted.");
						writeFile("File: '" + current.children.get(i).getFileName() + "' deleted.");
						current.children.get(i).remove();
						//System.out.println("found");
						return;
					}

				}
				System.out.println("rm: File not found");
				writeFile("rm: File not found");
			} else {
				System.out.println("usage: rm <filename>");
				writeFile("usage: rm <filename>");
				
			}
			break;
		case "rn":
			if(arguments!=null){
				if(arguments.length == 2){
					String oldname = arguments[0];
					String newname = arguments[1];
					
					for(int i =0; i<current.children.size();i++){
						if(current.children.get(i).getFileName().equals(oldname)){
							current.children.get(i).setFileName(newname);
							return;
						}
					}
					
					System.out.println("rn: cannot rename file. No such file or directory");
					writeFile("rn: cannot rename file. No such file or directory");
					
				}
				else{
					System.out.println("usage: rn <filename> <new filename>");
					writeFile("usage: rn <filename> <new filename>");
					
				}
			}
			else{
				System.out.println("usage: rn <filename> <new filename>");
				writeFile("usage: rn <filename> <new filename>");
			}
			break;
		case "mv":
			if(arguments!=null){
				if(arguments.length == 2){
					
					String arg1 = arguments[0];
					String arg2 = arguments[1];
					TreeNode tmp1 = null;
					System.out.println(arg1);
					System.out.println(arg2);
					
					for(int i=0; i <current.children.size();i++){
						if(current.children.get(i).getFileName().equals(arg1)){
							tmp1 = current.children.get(i);
						}
						
					}
					if(tmp1!=null){
						TreeNode tmp2 = null;
						for(int i=0; i<current.children.size();i++){
							if(current.children.get(i).getFileName().equals(arg2))
								tmp2 = current.children.get(i);
						}
						
						if(tmp2 == null){
							FileDescriptor information = new FileDescriptor(arg2, true);
							tmp2 = new TreeNode(information, current);
						}
						tmp1.remove();
						tmp1.insert(tmp2);

					}
					else{
						System.out.println("mv: File or Directory does not exist");
						writeFile("mv: File or Directory does not exist");
						
					}
				}
			}
			break;
		case "cp":
			//System.out.println("arguments length: "+arguments.length);
			if(arguments!=null){
				//System.out.println("hello");
				if(arguments.length==2){
					//System.out.println("hello");
					TreeNode copy = null;
					String original = arguments[0];
					String copyname = arguments[1];
					
					for(int i=0; i<current.children.size(); i++){
						if(current.children.get(i).getFileName().equals(original)){
							copy = current.children.get(i);
					
						}
					}
					if(copy==null){
						System.out.println("cp: Copy not created. File does not exist");
						writeFile("cp: Copy not created. File does not exist");
						return;
					}
					
					FileDescriptor copyinfo = new FileDescriptor(copyname, copy.fileDescriptor.isDIR);
					//System.out.println("current content: "+ copy.fileDescriptor.content);
					copyinfo.content = copy.fileDescriptor.content;
					copy = new TreeNode(copyinfo, current);
					
					
					
				}
				
			}
			else{
				System.out.println("usage: cp <filename> <copyfilename>");
				writeFile("usage: cp <filename> <copyfilename>");
			}
			break;
		case "exit":
			break;
		case ">":
			if (arguments != null) {
				String arg1 = arguments[0];
				info = new FileDescriptor(arg1, false);

				Scanner sc = new Scanner(System.in);
				info.content = "";
				info.content += sc.nextLine();
				TreeNode node = null;

				for (int i = 0; i < current.children.size(); i++) {
					if (current.children.get(i).getFileName().equals(arg1)) {
						node = current.children.get(i);

					}
				}
				if (node == null) {
					node = new TreeNode(info, current); // create new
					//System.out.println("HERE");
					//System.out.println(current.children.size());

				} else {

					node.fileDescriptor.content = info.content; // replace texts
				}

			} else {
				System.out.println("usage: > <filename>");
				writeFile("usage: > <filename>");
			}
			break;
		case ">>":
			if (arguments != null) {
				String arg1 = arguments[0];
				info = new FileDescriptor(arg1, false);

				Scanner sc = new Scanner(System.in);
				info.content = "";
				info.content += sc.nextLine();
				TreeNode node = null;

				for (int i = 0; i < current.children.size(); i++) {
					if (current.children.get(i).getFileName().equals(arg1)) {
						node = current.children.get(i);

					}
				}
				if (node == null) {
					node = new TreeNode(info, current); // create new
					//System.out.println("HERE");
					//System.out.println(current.children.size());

				} else {
					node.fileDescriptor.content += " ";
					node.fileDescriptor.content += info.content; // replace
																	// texts
				}

			} else {
				System.out.println("usage: >> <filename>");
				writeFile("usage: >> <filename>");
			}

			break;
		case "whereis":
			TreeNode tmpcurr = tree.root;
			if(arguments !=null){
				String arg1 =  arguments[0];
				//System.out.println(arg1);
				
				search(arg1, tmpcurr);
				

			}
			break;
		case "invalid":
			System.out.println("invalid command");
			writeFile("invalid command");
		}
	}
	
	public void search(String filename, TreeNode node){
		if(node.getFileName().equals(filename)){
			printDirectory(node.parent);
			System.out.println();
			writeFile("\n");
		}
		
		
		for(int i=0; i<node.children.size();i++){
			search(filename, node.children.get(i));
		}
	}

	public void userInput() {

		/// **eedit**//
		Scanner sc = new Scanner(System.in);

		while (command != "exit") {
			printDirectory(current);
			System.out.println("\nC:");
			String input = sc.nextLine();
			parse(input);

			execute(command);

		}
	}

	private void displayDialog(FileDescriptor info, TreeNode node) {
		JFrame frame = new JFrame("TextEditor");
		frame.setSize(450, 300);
		Dialog dialog = new Dialog(frame, "Want to Edit a file?");
		dialog.setBackground(Color.gray);
		dialog.setLayout(new BorderLayout());
		Panel panel = new Panel();
		Button b1 = new Button("Ok");
		panel.add(b1);
		dialog.add("South", panel);
		dialog.setSize(200, 200);
		dialog.setVisible(true);

		dialog.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent windowEvent) {
				frame.dispose();
			}
		});

		b1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				JFrame frame = new TextEditor(info, node);
				frame.pack();
				frame.setVisible(true);

				dialog.dispose();
			}
		});

	}

	public void parse(String input) {
		String path[] = input.split("\\s+");

		//System.out.println(path[0]);
		if (path[0].equals("mkdir") || path[0].equals("rmdir") || path[0].equals("cd") || path[0].equals("ls")
				|| path[0].equals("show") || path[0].equals("rm") || path[0].equals("mv") || path[0].equals(">")
				|| path[0].equals(">>") || path[0].equals("edit") || path[0].equals("exit") || path[0].equals("ls *")
				|| path[0].equals("cd ..") || path[0].equals("rn") || path[0].equals("whereis") || path[0].equals("cp")) {

			if (path.length == 1) {
				command = path[0];
				arguments = null;
			} else {
				command = path[0];
				arguments = Arrays.copyOfRange(path, 1, path.length);

			}

		} else {
			command = "invalid";
			arguments = Arrays.copyOf(path, path.length);
		}

	}

	/* edit */
	void printDirectory(TreeNode curr) {
		if (curr.parent != null) {
			printDirectory(curr.parent);
		}

		System.out.print(curr.getFileName());
		System.out.print("/");
	}
	/* edit */
}

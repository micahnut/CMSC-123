import java.io.*;
import java.util.*;



public class ChuIm1final{

		public int strToInt(String str){   //getting the int 
			
			int intValue;

			intValue = Integer.parseInt(str.trim());


			return intValue;
			
		}

		public boolean isNum(String str){		//checking if it is a number
			for(char c : str.toCharArray()){
				if(!Character.isDigit(c))
					return false;
			}
			return true;
		}

		public int getOperation(String str){	//getting what operation is in the iteration..i'+'=4 
			int x =0;
			for(int i=0;i< str.length();i++){
				if(str.charAt(i) == '*'){
					 x =1;
					break;
				}
				if(str.charAt(i) == '-'){
					 x =2;
					break;
				}
				if(str.charAt(i) == '+'){
					 x =3;
					break;
				}
				if(str.charAt(i) == '/'){
					 x =4;
					break;
				}


			}
			return x;
		}

		public int howManyMul(String str){		//counting how many * inside the condition token
			int counter=0;

			for(int i=0; i< str.length();i++){
				if(str.charAt(i) == '*')
					counter++;
			}

			return counter;
		}

		public int ifMinusMinus(String str){  //checking if the iteration is i--
			int mm=0;

			for(int i=0; i< str.length();i++){
				if(str.charAt(i) == '-')
					if(str.charAt(i+1) == '-'){
						mm=1;
						break;
					}
			}

			return mm;
		}

		public int ifPlusPLus(String str){	//checking if the iteration is i++
			int pp=0;

			for(int i=0; i< str.length();i++){
				if(str.charAt(i) == '+')
					if(str.charAt(i+1) == '+'){
						pp=1;
						break;
					}
			}

			return pp;
		}

		public boolean ifGreaterThan(String str){	// checking if the condition is inside the condition token is greater than
			for(int i=0;i<str.length();i++){
				if(str.charAt(i)== '>')
					return true;
			}
			return false;
		}


		public static void main(String[] args ){

				BufferedReader	br = null;
				BufferedWriter bw = null;
				String upperbound;
				String lowerbound;
				String iteration;
				String it;
				String ub;
				String lb;
				int flag=0;
				int count=0;
				int ub1=0;
				int lb1=0;
				int it1=0;
				int finalcount=0;
				int oper=0;
				int numOfM=0;
				int mm1=0;
				int pp1=0;
				int initCount=0;
				int iterCount=0;
				boolean ubchecker=true;
				boolean lbchecker=true;
				boolean itchecker=true;
				boolean conChecker=true;

			try{
					br = new BufferedReader(new FileReader("loops.txt"));	
					File file = new File("output.txt");

					if(!file.exists()){
						file.createNewFile();
					}

					FileWriter f = new FileWriter(file.getAbsoluteFile());
					bw = new BufferedWriter(f);

					String line;
					//StringBuilder sb = new StringBuilder();
					
					//line = br.readLine();

				while((line = br.readLine()) != null) {
					//System.out.println(line);

						List<String> tokens = new ArrayList<>();  //array list for tokens each line
						List<String> init = new ArrayList<>();		//array list for initializers..what if there are alot of lowerbounds
						List<String> iter = new ArrayList<>();		//array list for iterations..
					
					StringTokenizer strTokenizer= new StringTokenizer(line, "for({);");
									
						while(strTokenizer.hasMoreElements()) {

							String token = strTokenizer.nextElement().toString();
							tokens.add(token);		//array list for tokens

						}
						
						if(tokens.size()>2){
							ChuIm3 test = new ChuIm3(); 

							lowerbound = tokens.get(1);
							upperbound = tokens.get(2);
							iteration = tokens.get(3);
						
							
							StringTokenizer commaTokenizerin = new StringTokenizer(lowerbound, ","); //tokenizer for the lowerbound
							StringTokenizer commaTokenizerit = new StringTokenizer(iteration,","); //tokenizer for iterations
							
							while(commaTokenizerin.hasMoreElements()){
								String lbf = commaTokenizerin.nextElement().toString();   
								init.add(lbf);			 
							}

							while(commaTokenizerit.hasMoreElements()){
								String itf = commaTokenizerit.nextElement().toString();
								iter.add(itf);
							}	

							lowerbound = init.get(0);  //getting the first initilization inside the forloop
							iteration = iter.get(0); //getting the first iteration inside the forloop

							initCount = init.size();	//counting how many initializations
							//System.out.println("initCount:"+initCount);
							//System.out.println(init);

							iterCount = iter.size();	//counting how many iterations
							//System.out.println("iterCount:"+iterCount);
							//System.out.println(iter);							
								
							
							//System.out.println("upperboundfinal:"+upperbound);
							//System.out.println("iterationfinal:"+iteration);
							//System.out.println("lowerboundfinal:"+lowerbound);
							
							
							oper= test.getOperation(iteration); 	
							numOfM = test.howManyMul(upperbound);
							conChecker=test.ifGreaterThan(upperbound);

							//System.out.println("numOfM ="+ numOfM);
							//System.out.println("CONCHECKER ="+ numOfM);

							/*
							**
								Assumes that the first one initialized is the lowerbound
							**	and assumes the first one iterated is the iteration
							*/

							lb = lowerbound.substring(lowerbound.lastIndexOf('=')+1);
							ub = upperbound.substring(upperbound.lastIndexOf('=')+1);
							it = iteration.substring(iteration.lastIndexOf('=')+1);

							//System.out.println("lower bound :"+lb);
							//System.out.println("upper bound: "+ub);
							//System.out.println(it);


							ub= ub.trim();       /** incase there are still spaces**/
							lb = lb.trim();			
							it = it.trim();			

							if(conChecker==true){
								ub= upperbound.substring(upperbound.lastIndexOf('>')+1);
								ub= ub.trim();
							}

							//System.out.println(lb);
							//System.out.println(ub);
							//System.out.println(it);

							if(test.isNum(ub)){
								//System.out.println("QWERTY1");
								ub1 = test.strToInt(ub);
								//System.out.println(ub1);
								ubchecker=true;
								
							}
							else{
								//System.out.println("QWERTY2");
								ubchecker = false;
							}
								
							if(test.isNum(lb)){
								//System.out.println("QWERTY1.2");
								lb1 = test.strToInt(lb);
								lbchecker=true;
							}
							else{
								//System.out.println("QWERTY2.1");
								lbchecker=false;
							}
							if(test.isNum(it)){
								//System.out.println("QWERTY3.1");
								it1 = test.strToInt(it);
								itchecker=true;
							}
							else{
								//System.out.println("QWERTY3.2");
								mm1 = test.ifMinusMinus(it);
								pp1 = test.ifMinusMinus(it);
								itchecker=false;

							}

						}

						if(tokens.size()==1){       //**counting how many counts inside the forloop**//
							String tok = tokens.get(0);
							for(int i=0;i<tok.length();i++){

								if(tok.charAt(i) == '=' || tok.charAt(i) == '+' || tok.charAt(i) == '-' || tok.charAt(i)  == '*' || tok.charAt(i) == '/' || tok.charAt(i) =='%')
										count++;

								if(flag!=1){
								if(tok.charAt(i) == '=' || tok.charAt(i) == '+' || tok.charAt(i) == '-' || tok.charAt(i)  == '*' || tok.charAt(i) == '/' || tok.charAt(i) =='%'){
									if(tok.charAt(i+1) == '=' || tok.charAt(i+1) == '+' || tok.charAt(i+1) == '-' || tok.charAt(i+1)  == '*' || tok.charAt(i+1) == '/' || tok.charAt(i+1) =='%')
										count--;
										flag=1;
								}	
								}

							}
							flag=0;

							//System.out.println("insideforloopcount:"+count);
							//System.out.println("QWERTY30");	
							
							int s=0;
							
							if(tok.charAt(s) == '}'){				//*for printing the t(n)*//
								if(count==0){						
									//System.out.println("QWERTY31");
									finalcount = initCount + iterCount;
									System.out.println("T(n)="+finalcount);
									bw.write("T(n)="+finalcount);
									bw.newLine();
								}
								else{
									if(lb1!=1){
										//System.out.println("QWERTY32");
										if(ubchecker == false){
											if(itchecker==true){
												//System.out.println("QWERTY33");
												//System.out.println("second1:"+count);
												count = (count+iterCount+1); 
												//System.out.println("third1:"+count);
												finalcount= (count)*((-lb1)+1);
												//System.out.println("fourth1:"+finalcount);
												finalcount = finalcount +initCount+1;

											if(oper==1){

												//	System.out.println("QWERTY34");
												if(finalcount>0){
												//	System.out.println("QWERTY35");
													System.out.println("T(n)="+count+"log("+it1+")"+"n"+"+"+finalcount);
													bw.write("T(n)="+count+"log("+it1+")"+"n"+"+"+finalcount);
													bw.newLine();
												}
												else{
												//	System.out.println("QWERTY36");
													System.out.println("T(n)="+count+"log("+it1+")"+"n"+finalcount);
													bw.write("T(n)="+count+"log("+it1+")"+"n"+finalcount);
													bw.newLine();
												}
											}

											else if(oper==2 || oper==3){
												//System.out.println("QWERTY37");
												if(finalcount>0){
												//	System.out.println("QWERTY38");
													System.out.println("T(n)="+count+"n"+"/"+it1+"+"+finalcount);
													bw.write("T(n)="+count+"n"+"/"+it1+"+"+finalcount);
													bw.newLine();
												}
												else{
												//	System.out.println("QWERTY38");
													System.out.println("T(n)="+count+"n"+"/"+it1+finalcount);
													bw.write("T(n)="+count+"n"+"/"+it1+finalcount);
													bw.newLine();

												}

											}



										}
										else{
											//System.out.println("QWERTY39");
											//System.out.println("second1.2:"+count);
											count = (count+iterCount+1);
											//System.out.println("third1.2:"+count);
											finalcount= (count)*((-lb1)+1);
											//System.out.println("finalcount:"+finalcount);
											finalcount = finalcount +initCount+1;

											if(finalcount>0){
												//System.out.println("QWERTY40");
												System.out.println("T(n)="+count+"n"+"+"+finalcount);
												bw.write("T(n)="+count+"n"+"+"+finalcount);
												bw.newLine();
											}
											else{
												//System.out.println("QWERTY41");
												System.out.println("T(n)="+count+"n"+finalcount);	
												bw.write("T(n)="+count+"n"+finalcount);
												bw.newLine();
											}
										}
									}
									else{
										if(itchecker==true){
											//System.out.println("QWERTY42");
											if(ub1 == 1  && conChecker == true){
												//System.out.println("QWERTY43");
												//System.out.println("second1.2");
												finalcount = finalcount+initCount+1;
												System.out.println("T(n)=" + finalcount);
												bw.write("T(n)=" + finalcount);
												bw.newLine();
											}
											else{
												//System.out.println("QWERTY44");
												//System.out.println("second1:"+count);
												count = (count+iterCount+1);
												//System.out.println("third1:"+count);
												finalcount = finalcount+initCount +1;

												//System.out.println("FINALCOUNT"+ finalcount);

											if(oper==1){

												if(finalcount>0){
													//System.out.println("QWERTY00");
													System.out.println("T(n)="+count+"log("+it1+")"+"n"+"+"+finalcount);
													bw.write("T(n)="+count+"log("+it1+")"+"n"+"+"+finalcount);
													bw.newLine();
												}
												else{
													//System.out.println("QWERTY01");
													System.out.println("T(n)="+count+"log("+it1+")"+"n"+finalcount);
													bw.write("T(n)="+count+"log("+it1+")"+"n"+finalcount);
													bw.newLine();

												}
											}


											else if(oper==2 || oper==3){
												//System.out.println("QWERTY02");
												if(finalcount>0){
													//System.out.println("QWERTY03");
													System.out.println("T(n)="+count+"n"+"/"+it1+"+"+finalcount);
													bw.write("T(n)="+count+"n"+"/"+it1+"+"+finalcount);
													bw.newLine();
												}
												else{
													//System.out.println("QWERTY04");
													System.out.println("T(n)="+count+"n"+"/"+it1+finalcount);
													bw.write("T(n)="+count+"n"+"/"+it1+finalcount);
													bw.newLine();

												}	

											}
											else if(oper == 4){
												
													//System.out.println("QWERTY14");
													System.out.println("T(n)="+finalcount);
													bw.write("T(n)="+finalcount);
													bw.newLine();

											}

											}
										}	
										
										else{

											//System.out.println("second2:"+count);	
											count = (count+iterCount+1)*((ub1-lb1)+1);
											//System.out.println("third2:"+count);
											count = count+initCount+1;
										
											System.out.println("T(n)="+ count);	
											bw.write("T(n)="+ count);
											bw.newLine();
										}
									}

								}

								else{
									 //System.out.println("QWERTY");

									if(ubchecker==false){
										if(itchecker==true){
											//System.out.println("QWERTY111");
											count = count + iterCount + 1;
											finalcount = finalcount + initCount + 1;
											
											if(oper==1){
												//System.out.println("QWERTY1.0");
												if(finalcount>0){
													//System.out.println("QWERTY1.1");
													System.out.println("T(n)="+count+"log("+it1+")"+"n"+"+"+finalcount);
													bw.write("T(n)="+count+"log("+it1+")"+"n"+"+"+finalcount);
													bw.newLine();
												}
												else{
													//System.out.println("QWERTY1.2");
													System.out.println("T(n)="+count+"log("+it1+")"+"n"+finalcount);
													bw.write("T(n)="+count+"log("+it1+")"+"n"+finalcount);
													bw.newLine();
												}
											}

											else if(oper==2 || oper==3){
												//System.out.println("QWERTY2");
												if(finalcount>0){
													//System.out.println("QWERTY2.1");
													System.out.println("T(n)="+count+"n"+"/"+it1+"+"+finalcount);
													bw.write("T(n)="+count+"n"+"/"+it1+"+"+finalcount);
													bw.newLine();
												}
												else{
													//System.out.println("QWERTY2.2");
													System.out.println("T(n)="+count+"n"+"/"+it1+finalcount);
													bw.write("T(n)="+count+"n"+"/"+it1+finalcount);
													bw.newLine();

												}
											}

										}
										else{

											if(mm1 == 1){
												System.out.println("T(n)=Infinite");
												bw.write("Infinite");
												bw.newLine();
											}
											
											else{
												if(numOfM>=1){
													if(numOfM == 1){
														//System.out.println("QWERTY 1.1");
														count = count + iterCount +1 + numOfM;
														finalcount = finalcount + initCount +1 + numOfM;

														System.out.println("T(n)="+count+"sqrt(n)"+"+"+finalcount);
														bw.write("T(n)="+count+"sqrt(n)"+"+"+finalcount);
														bw.newLine();

													}
													else{
														//System.out.println("QWERTY 1.1.1");
														count = count + iterCount + 1 + numOfM;
														finalcount = finalcount + initCount + 1 + numOfM;

														System.out.println("T(n)="+count+"cubert(n)"+"+"+finalcount);
														bw.write("T(n)="+count+"cubert(n)"+"+"+finalcount);
														bw.newLine();
													}

												}
											
												else{   
													//System.out.println("QWERTY1.2");
													count = count +iterCount+1;
													finalcount = finalcount+initCount+1;
													
													System.out.println("T(n)="+count+"n"+"+"+finalcount);
													bw.write("T(n)="+count+"n"+"+"+finalcount);
													bw.newLine();
												}
											}
										}	
									}
									else{

										if(conChecker==true){
											//System.out.println("QWERTY2.1");
											finalcount = finalcount + initCount + 1;
											System.out.println("T(n)=" +finalcount);
											bw.write("T(n)=" +finalcount);
											bw.newLine();
										}

										else{
											//System.out.println("QWERTY2");
											count = (count+iterCount+1)*ub1; 
											count = count+initCount+1;
											System.out.println("T(n)="+ count);	
											bw.write("T(n)="+ count);
											bw.newLine();
										}
									}
								}

								 
								}
								count =0;
								 ub1=0;
								 lb1=0;
				   	          	 it1=0;
								 finalcount=0;
								 ubchecker = true;
								 lbchecker = true;
								 itchecker=true;
								 flag=0;
								 oper=0;
								 numOfM=0;
					 			 mm1=0;
								 pp1=0;
								 conChecker=true;
								 initCount=0;
								 iterCount=0;
								 
							}	
								 					
						}

			
						//System.out.println(tokens);


				
				}

			}

			catch(IOException e){
				e.printStackTrace();
			}
		
			finally{
				try{
					br.close();
					bw.close();
				}
				catch(IOException x){
					x.printStackTrace();
				}		
			}	
		

	}

}

import java.util.*;
import java.io.*;

public class Enclosure{
	public static ArrayList<Integer> getPositions(String operations){
		ArrayList<Integer> answers=new ArrayList<Integer>();
		Boolean open=false;
		Integer position = null;
		for(int i=0; i<operations.length(); i++){
			if(operations.charAt(i)=='('){
				open=true;
				position=i;
				break;
			}else if(operations.charAt(i)==')'){
				position=i;
				break;
			}
		}
		if(open){
			for(int j=position+2; j<operations.length(); j++){
				if(operations.charAt(j)!='+'&&operations.charAt(j)!='-'&&operations.charAt(j)!='/'&&operations.charAt(j)!='*'){
					answers.add(j+2);
				}
			}
		}else{
			for(int j=position-2; j>=0; j--){
				if(operations.charAt(j)!='+'&&operations.charAt(j)!='-'&&operations.charAt(j)!='/'&&operations.charAt(j)!='*'){
					answers.add(j+1);
				}
			}
		}
		return answers;
	}
	public static void main(String args[]){
		int bob=6/3;
		System.out.println(bob);
		Scanner kevinisdumb=new Scanner(System.in);
		for(int i=0; i<5; i++){
			String operations=kevinisdumb.next();
			ArrayList<Integer> answers=new ArrayList<Integer>();
			answers=getPositions(operations);
			Collections.sort(answers);
			for(int j=0; j<answers.size(); j++){
				System.out.print(answers.get(j)+" ");
			}
			System.out.println();
		}
		kevinisdumb.close();
	}
}
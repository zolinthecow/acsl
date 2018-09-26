import java.util.*;
import java.io.*;

public class abc{
	
	public static Boolean isSolved(Integer[]board){
		if(board[1]!=board[2] && board[2]!=board[3] && board[1]!=board[3]){
			if(board[4]!=board[5] && board[5]!=board[6] && board[4]!=board[6]){
				if(board[7]!=board[8] && board[8]!=board[9] && board[7]!=board[9]){
					if(board[1]!=board[4] && board[4]!=board[7] && board[1]!=board[7]){
						if(board[2]!=board[5] && board[5]!=board[8] && board[2]!=board[8]){
							if(board[3]!=board[6] && board[6]!=board[9] && board[3]!=board[9]){
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
	public static Integer[] findTwo(Integer[] board, int a, int b, int c){
		int place=-1;
		if(board[a]==0){
			place=a;
		}else if(board[b]==0){
			place=b;
		}else if(board[c]==0){
			place=c;
		}
		if(place!=-1){
			board[place]=6-(board[0]+board[1]+board[2]);
		}
		return board;
	}
	public static Integer[] twoSame(Integer[]board){
		int aCount=0, bCount=0, cCount=0;
		for(int i=0; i<9; i++){
			if(board[i]==1){
				aCount++;
			}else if(board[i]==2){
				bCount++;
			}else if(board[i]==3){
				cCount++;
			}
		}
		if(aCount==2){
			ArrayList<Integer> aRows=new ArrayList<Integer>();
			ArrayList<Integer> aColumn=new ArrayList<Integer>();
			for(int j=0; j<9; j++){	
				if(board[j]==1){
					aRows.add(j/3);
					aColumn.add(j%3);
				}
			}
			int aRowsTotal=0, aColumnTotal=0;
			for(int k=0; k<aRows.size(); k++){
				aRowsTotal+=aRows.get(k);
				aColumnTotal+=aColumn.get(k);
			}
			aRowsTotal=6-aRowsTotal;
			aColumnTotal=6-aColumnTotal;
			int placeToInsert=aRowsTotal*3+aColumnTotal-3;
			board[placeToInsert]=1;
		}
		if(bCount==2){
			ArrayList<Integer> bRows=new ArrayList<Integer>();
			ArrayList<Integer> bColumn=new ArrayList<Integer>();
			for(int j=0; j<9; j++){	
				if(board[j]==1){
					bRows.add(j/3);
					bColumn.add(j%3);
				}
			}
			int bRowsTotal=0, bColumnTotal=0;
			for(int k=0; k<bRows.size(); k++){
				bRowsTotal+=bRows.get(k);
				bColumnTotal+=bColumn.get(k);
			}
			bRowsTotal=6-bRowsTotal;
			bColumnTotal=6-bColumnTotal;
			int placeToInsert=bRowsTotal*3+bColumnTotal-3;
			board[placeToInsert]=2;
		}
		if(cCount==2){
			ArrayList<Integer> cRows=new ArrayList<Integer>();
			ArrayList<Integer> aColumn=new ArrayList<Integer>();
			for(int j=0; j<9; j++){	
				if(board[j]==1){
					cRows.add(j/3);
					aColumn.add(j%3);
				}
			}
			int cRowsTotal=0, aColumnTotal=0;
			for(int k=0; k<cRows.size(); k++){
				cRowsTotal+=cRows.get(k);
				aColumnTotal+=aColumn.get(k);
			}
			cRowsTotal=6-cRowsTotal;
			aColumnTotal=6-aColumnTotal;
			int placeToInsert=cRowsTotal*3+aColumnTotal-3;
			board[placeToInsert]=3;
		}
		return board;
	}
	public static Integer[] fillBoard(Integer[] board){
		while(!isSolved(board)){
			board=findTwo(board, 0, 1, 2);
			board=findTwo(board, 3, 4, 6);
			board=findTwo(board, 6, 7, 8);
			board=findTwo(board, 0, 3, 6);
			board=findTwo(board, 1, 4, 7);
			board=findTwo(board, 2, 5, 8);
			Integer[] tempBoard=new Integer[9];
			tempBoard=twoSame(board);
			while(tempBoard!=board){
				board=tempBoard;
				tempBoard=twoSame(board);
			}
		}
		return board;
	}
	public static void main(String Args[]) throws IOException{
		Scanner cin = new Scanner(System.in);
		Integer amount=cin.nextInt();
		Integer[] board;
		board=new Integer[9];
		for(int z=0; z<9; z++){
			board[z]=0;
		}
		for(int i=0; i<amount; i++){
			int place=cin.nextInt(), realLetter=0;
			String letter=cin.next();
			switch(letter){
			case "A":
				realLetter=1;
				break;
			case "B":
				realLetter=2;
				break;
			case "C":
				realLetter=3;
				break;
			}
			board[place]=realLetter;
		}
		board=fillBoard(board);
		for(int j=0; j<9; j++){
			if(board[j]==1){
				System.out.println("A");
			}else if(board[j]==2){
				System.out.println("B");
			}else{
				System.out.println("C");
			}
		}
		cin.close();
	}
}
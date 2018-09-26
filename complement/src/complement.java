import java.io.*;
import java.util.*;

public class complement{
	
	public static String twosComplement(Integer a){
		String aTemp;
		if(a>=0){
			aTemp="0";
		}else{
			aTemp="1";
		}
		String aBin=Integer.toBinaryString(a);
		aTemp+=aBin;
		for(int i=0; i<aTemp.length(); i++){
			if(aTemp.charAt(i)=='0'){
				String temp1=aTemp.substring(0, i), temp2=aTemp.substring(i+1, aTemp.length());
				aTemp=temp1+"1"+temp2;
			}else{
				String temp1=aTemp.substring(0, i), temp2=aTemp.substring(i+1, aTemp.length());
				aTemp=temp1+"0"+temp2;
			}
		}
		Integer aBinT=Integer.parseInt(aTemp, 2);
		aBinT+=1;
		return Integer.toBinaryString(aBinT);
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		in.useDelimiter(",|\\s");
		Integer minuend, subtrahend;
		minuend=in.nextInt();
		subtrahend=in.nextInt();
		String minBin=Integer.toBinaryString(minuend);
		String subBin=Integer.toBinaryString(subtrahend);
		Integer longest=Math.max(minBin.length(), subBin.length());
		minBin=minBin.substring(minBin.length()-longest);
		subBin=subBin.substring(subBin.length()-longest);
		System.out.println(minBin);
		System.out.println(subBin);
		String subBinComp=twosComplement(subtrahend);
		String minBinComp=twosComplement(minuend);
		System.out.println(subBinComp);
		System.out.println(minBinComp);
		String sum=Integer.toBinaryString(minuend+Integer.parseInt(subBinComp, 2));
		if(sum.length()>Math.max(subBinComp.length(), minBin.length())){
			sum=sum.substring(1, sum.length());
			if(sum.charAt(0)=='0'){
				System.out.println(sum);
			}else{
				System.out.println(twosComplement(Integer.parseInt(sum, 2)));
			}
		}else{
			if(sum.charAt(0)=='0'){
				System.out.println(sum);
			}else{
				sum=sum.substring(1, sum.length());
				System.out.println(twosComplement(Integer.parseInt(sum, 2)));
			}
		}
	}
}

package util;

public class CurrencyConverter {
	public static final double IOF = 0.06;
	
	public static double moneyConversion(double amount, double price){
		double conversion = amount * price;
		
		return conversion * (IOF + 1); // * 1.06 pq é um acrescimo de 6% do valor total desejado
	}									// ou  conversion + (conversion * IOF)
	
}

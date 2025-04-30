package entities;

public class Account {
	private int id;
	private String name;
	private double balance;
	
	public Account(int id, String name) {
		this.id = id;
		this.name = name;
	}

	public Account(int id, String name, double initialDeposit) {
		this.id = id;
		this.name = name;
		deposit(initialDeposit);
	}

	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getBalance() {
		return balance;
	}
	
	public void deposit(double amount) {
		balance += amount;
	}
	
	public void withdraw(double amount) {
		if (amount != 0.00) {
			balance -= amount + 5.00;
		}
	}

	public String toString() {
		return "Account "
				+ id
				+ ", Holder: "
				+ name
				+ ", Balance: $"
				+ String.format("%.2f", balance);
	}


	
	
}

package application;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

import entities.Employee;

public class Program {

	public static void main(String[] args) {

		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);

		List<Employee> list = new ArrayList<>();

		System.out.print("How many employees will be registered? ");
		Integer n = sc.nextInt();
		System.out.println();

		for (int i = 0; i < n; i++) {
			System.out.println("Employee #" + (i + 1) + ":");
			System.out.print("ID: ");
			Integer id = sc.nextInt();
			System.out.print("Name: ");
			sc.nextLine();
			String name = sc.nextLine();
			System.out.print("Salary: ");
			Double salary = sc.nextDouble();

			Employee emp = new Employee(id, name, salary);

			list.add(emp);
			System.out.println();
		}

		System.out.println();
		System.out.println("Enter the employee ID that will have salary increase: ");
		int idsalary = sc.nextInt();

//		Employee emp = list.stream().filter(x -> x.getId() == id).findFirst().orElse(null);;
//		if (emp == null) {
//			System.out.println("This ID does NOT exist!");
//		}
//		else {
//			System.out.println("Enter the percentage");
//			double percentage = sc.nextDouble();
//			emp.increaseSalary(percentage);
//		}

		Integer pos = position(list, idsalary);

		if (pos == null) {
			System.out.println("This ID does NOT exist!");
		} else {
			System.out.println("Enter the percentadge");
			double percentage = sc.nextDouble();
			list.get(pos).increaseSalary(percentage);
		}

		System.out.println();
		System.out.println("List of Employees: ");
		for (Employee emp : list) {
			System.out.println(emp);
		}

		sc.close();
	}

	public static Integer position(List<Employee> list, int id) {
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).getId() == id) {
				return i;
			}
		}
		return null;
	}
}

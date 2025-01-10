import java.util.*;

class Process {
    String name;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int initialQuantum;
    List<Integer> quantumHistory;
    
    public Process(String name, int arrivalTime, int burstTime, int priority, int initialQuantum) {
        this.name = name;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
        this.priority = priority;
        this.remainingTime = burstTime;
        this.initialQuantum = initialQuantum;
        this.quantumHistory = new ArrayList<>();
    }

    public void addQuantum(int quantum) {
        quantumHistory.add(quantum);
    }
}

public class inputHandler {
    public static List<Process> getProcesses() {
        List<Process> processes = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int n = Integer.parseInt(scanner.nextLine().trim()); // Always use nextLine() and parse

        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Process " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine().trim();

            System.out.print("Arrival Time: ");
            int arrivalTime = Integer.parseInt(scanner.nextLine().trim());

            System.out.print("Burst Time: ");
            int burstTime = Integer.parseInt(scanner.nextLine().trim());

            System.out.print("Priority: ");
            int priority = Integer.parseInt(scanner.nextLine().trim());

            System.out.print("Initial Quantum: ");
            int initialQuantum = Integer.parseInt(scanner.nextLine().trim());


            // Add process to the list
            processes.add(new Process(name, arrivalTime, burstTime, priority, initialQuantum));
        }

        return processes;
    }
}
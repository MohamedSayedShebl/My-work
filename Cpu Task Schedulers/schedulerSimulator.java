import java.util.*;

public class schedulerSimulator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get process inputs
        List<Process> processes = inputHandler.getProcesses();

        // Menu for selecting scheduler
        boolean running = true;

        while (running) {
            System.out.println("\nSelect a Scheduler:");
            System.out.println("1. Non-Preemptive Priority Scheduling");
            System.out.println("2. Non-Preemptive Shortest Job First (SJF)");
            System.out.println("3. Shortest Remaining Time First (SRTF)");
            System.out.println("4. FCAI Scheduling");
            System.out.println("5. Exit");
            System.out.print("Your choice: ");

            String choice = scanner.nextLine().trim(); // Read choice as a string

            int[] completionTimes = null;

            int contextSwitchTime = 0;

            switch (choice) {
                case "1":
                // Context switching time
                    System.out.print("\nInput context switching time: ");
                    contextSwitchTime = Integer.parseInt(scanner.nextLine().trim());

                    System.out.println("\nRunning Non-Preemptive Priority Scheduling...");
                    completionTimes = priorityScheduler.schedule(cloneProcesses(processes), contextSwitchTime);

                    // Calculate and display metrics
                    metricsCalculator.calculate(processes, completionTimes);
                    break;

                case "2":
                    System.out.println("\nRunning Non-Preemptive Shortest Job First (SJF)...");
                    completionTimes = SJFScheduler.schedule(cloneProcesses(processes));

                    // Calculate and display metrics
                    metricsCalculator.calculate(processes, completionTimes);
                    break;

                case "3":
                    // Context switching time
                    System.out.print("\nInput context switching time: ");
                    contextSwitchTime = Integer.parseInt(scanner.nextLine().trim());

                    System.out.println("\nRunning Shortest Remaining Time First (SRTF)...");
                    completionTimes = SRTFScheduler.schedule(cloneProcesses(processes), contextSwitchTime);

                    // Calculate and display metrics
                    metricsCalculator.calculate(processes, completionTimes);
                    break;

                    case "4":
                    System.out.println("\nRunning FCAI Scheduling...");
                    completionTimes = FCAIScheduler.schedule(cloneProcesses(processes));
                
                    // Calculate and display metrics
                    metricsCalculator.calculate(processes, completionTimes);
                    break;

                case "5":
                    System.out.println("\nExiting... Goodbye!");
                    running = false;
                    break;

                default:
                    System.out.println("\nInvalid choice. Please enter a valid option (1-5).");
            }
        }

        scanner.close();
    }

    // Utility method to clone processes for each scheduler
    private static List<Process> cloneProcesses(List<Process> original) {
        List<Process> clone = new ArrayList<>();
        for (Process p : original) {
            clone.add(new Process(p.name, p.arrivalTime, p.burstTime, p.priority, p.initialQuantum));
        }
        return clone;
    }
}
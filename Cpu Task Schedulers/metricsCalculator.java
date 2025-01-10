import java.util.*;

public class metricsCalculator {
    public static void calculate(List<Process> processes, int[] completionTimes) {
        int n = processes.size();
        int totalWaitingTime = 0, totalTurnaroundTime = 0;

        for (int i = 0; i < n; i++) {
            Process p = processes.get(i);

                int turnaroundTime = completionTimes[i] - p.arrivalTime;
                int waitingTime = turnaroundTime - p.burstTime;

                // Ensure waiting time is not negative
                waitingTime = Math.max(waitingTime, 0);

                totalWaitingTime += waitingTime;
                totalTurnaroundTime += turnaroundTime;

                System.out.println("Process: " + p.name);
                System.out.println("Waiting Time: " + waitingTime);
                System.out.println("Turnaround Time: " + turnaroundTime);
        }

        System.out.println("Average Waiting Time: " + (double) totalWaitingTime / n);
        System.out.println("Average Turnaround Time: " + (double) totalTurnaroundTime / n);
    }
}
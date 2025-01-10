import java.util.*;

public class FCAIScheduler {
    
    // Calculate V1 and V2 based on the input processes
    private static double calculateV1(List<Process> processes) {
        double lastArrivalTime = processes.get(processes.size() - 1).arrivalTime;
        return lastArrivalTime / 10.0;
    }

    private static double calculateV2(List<Process> processes) {
        int maxBurstTime = processes.stream().mapToInt(p -> p.burstTime).max().orElse(0);
        return maxBurstTime / 10.0;
    }

    // Calculate FCAI factor for each process
    private static double calculateFCAIFactor(Process process, double V1, double V2) {
        return (10 - process.priority) + (process.arrivalTime / V1) + (process.remainingTime / V2);
    }

    // Run FCAI Scheduling
    public static int[] schedule(List<Process> processes) {
        List<Process> queue = new ArrayList<>(processes);
        queue.sort(Comparator.comparingInt(p -> p.arrivalTime)); // Sort by arrival time

        double V1 = calculateV1(queue);
        double V2 = calculateV2(queue);
        
        int[] completionTimes = new int[queue.size()];
        int currentTime = 0;
        int completed = 0;
        int totalProcesses = queue.size();
        
        // To track the execution order
        List<String> executionOrder = new ArrayList<>();
        
        while (completed < totalProcesses) {
            // Calculate FCAI for all processes
            List<Process> readyQueue = new ArrayList<>();
            for (Process process : queue) {
                if (process.arrivalTime <= currentTime && process.remainingTime > 0) {
                    readyQueue.add(process);
                }
            }

            if (!readyQueue.isEmpty()) {
                // Sort the ready queue by FCAI factor in ascending order
                readyQueue.sort(Comparator.comparingDouble(p -> calculateFCAIFactor(p, V1, V2)));
                Process currentProcess = readyQueue.get(0);
                int quantum = currentProcess.initialQuantum;

                // Calculate the execution time based on the process state and remaining burst time
                int executionTime = Math.min(quantum, currentProcess.remainingTime);

                // Add execution time to the process and update remaining time
                currentProcess.remainingTime -= executionTime;
                currentTime += executionTime;
                executionOrder.add(currentProcess.name);
                currentProcess.addQuantum(executionTime);
                
                // Check if the process is completed
                if (currentProcess.remainingTime == 0) {
                    completionTimes[processIndex(currentProcess, processes)] = currentTime;
                    completed++;
                }

                // Update quantum for the next round
                if (currentProcess.remainingTime > 0) {
                    // Apply dynamic quantum rules
                    if (executionTime == quantum) {
                        currentProcess.initialQuantum += 2;
                    } else {
                        currentProcess.initialQuantum += currentProcess.initialQuantum;
                    }
                }
            } else {
                // No process is ready, move time forward
                currentTime++;
            }
        }

        // Print execution order and quantum history
        System.out.println("Execution Order: " + String.join(" -> ", executionOrder));
        for (Process p : processes) {
            System.out.println(p.name + " Quantum History: " + p.quantumHistory);
        }

        return completionTimes;
    }

    // Helper method to find the index of a process in the original list
    private static int processIndex(Process process, List<Process> originalList) {
        for (int i = 0; i < originalList.size(); i++) {
            if (originalList.get(i).name.equals(process.name)) {
                return i;
            }
        }
        throw new IllegalArgumentException("Process not found: " + process.name);
    }

}
import java.util.Scanner;
import java.util.Arrays;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class CommandLineInterpreter {

    private Cd cd;// Instance of Cd to manage directory changes

    public CommandLineInterpreter() {
        this.cd = new Cd(); // Constructor initializing cd
    }
    public static void main(String[] args) {
        CommandLineInterpreter cli = new CommandLineInterpreter();
        cli.start();
    }

    public void start() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to CLI! Type 'help' for a list of commands.");

        while (true) {
            System.out.print("CLI> ");
            String input = scanner.nextLine();
            handleCommand(input);
        }
    }

    public void handleCommand(String input) {
        String[] parts = input.trim().split("\\s+");

        if (input.contains("|")) {
            // Split the commands based on the pipe symbol
            String[] commands = input.split("\\|");
            List<String> commandList = new ArrayList<>();
    
            for (String cmd : commands) {
                commandList.add(cmd.trim());
            }
    
            // Execute the pipeline
            new PipelineCommand(commandList).execute();
            return;
        }
        if (parts.length > 2 && ">>".equals(parts[parts.length - 2])) {
            String filename = parts[parts.length - 1]; // Get the file name
            String command = String.join(" ", Arrays.copyOf(parts, parts.length - 2)); // Command before ">>"
            
            // Capture the command output
            String outputToAppend = captureCommandOutput(command);

            // Execute the append command to append output to file
            new AppendCommand().execute(new String[]{filename, outputToAppend});
            return;
        } else if (parts.length > 1 && ">>".equals(parts[parts.length - 1])) {
            System.out.println("Error: No output file specified.");
            return;
        } else if (parts.length > 1 && ">".equals(parts[parts.length - 2])) {
            String command = String.join(" ", Arrays.copyOf(parts, parts.length - 2)); // Command without ">"
            String filename = parts[parts.length - 1]; // File to overwrite
    
            String output = captureCommandOutput(command);
            // Execute the redirect command
            new RedirectCommand().execute(output, filename);
            return;
        } else if (parts.length > 1 && ">".equals(parts[parts.length - 1])) {
            System.out.println("Error: No output file specified.");
            return;
        }
        String commandName = parts[0];
        String[] arguments = new String[parts.length - 1];
        System.arraycopy(parts, 1, arguments, 0, parts.length - 1);

        switch (commandName) {
            case "pwd":
                new PwdCommand().execute();
                break;
            case "cd":
                cd.execute(parts);
                break;
            case "touch":
                new TouchCommand().execute(arguments);
                break;
            case "ls":
                new LsCommand().execute(arguments);
                break;
            case "mv":
                new MvCommand().execute(arguments);
                break;
            case "rm":
                new RmCommand().execute(arguments);
                break;
            case "cat":
                new CatCommand().execute(arguments);
                break;
            case "mkdir":
                new MkdirCommand().execute(arguments);
                break;
            case "rmdir":
                new RmdirCommand().execute(arguments);
                break;
            case "exit":
                System.out.println("Exiting...");
                System.exit(0);
                break;
            case "help":
                printHelp();
                break;
            default:
                System.out.println("Invalid command. Type 'help' for a list of commands.");
                break;
        }
    }

    private String captureCommandOutput(String command) {
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        PrintStream printStream = new PrintStream(outputStream);
        PrintStream originalOut = System.out;
            // Redirect System.out to the ByteArrayOutputStream
            System.setOut(printStream);

            // Execute the command
            CommandLineInterpreter cli = new CommandLineInterpreter();
            cli.handleCommand(command);

            // Restore System.out
            System.setOut(originalOut);

            String output = outputStream.toString();

            return output;
}

    private void printHelp() {
        System.out.println("Available commands:");
        System.out.println("pwd                - Print the current working directory.");
        System.out.println("cd <dir>           - Change the current directory to <dir>.");
        System.out.println("ls                 - List files in the current directory.");
        System.out.println("ls -a              - List all files, including hidden files.");
        System.out.println("ls -r              - List files in reverse order.");
        System.out.println("mkdir <dir>        - Create a new directory named <dir>.");
        System.out.println("rmdir <dir>        - Remove the directory named <dir>.");
        System.out.println("touch <file>       - Create a new empty file named <file>.");
        System.out.println("mv <src> <dest>    - Move or rename a file or directory.");
        System.out.println("rm <file>          - Delete the file named <file>.");
        System.out.println("cat <file>[file2] ...         - Display the contents of <file>.");
        System.out.println("> <file>           - Redirect output to <file>, overwriting its contents.");
        System.out.println(">> <file>          - Redirect output to <file>, appending to its contents.");
        System.out.println("|                  - Pipe output of one command to another.");
        System.out.println("exit               - Exit the command line interpreter.");
        System.out.println("help               - Display this help message.");
    }
}

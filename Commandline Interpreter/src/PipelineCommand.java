import java.util.List;

public class PipelineCommand {
    private List<String> commands;
    private Cd cd;
    public PipelineCommand(List<String> commands) {
        this.commands = commands;
        this.cd = new Cd();
    }

    public void execute() {
        for (String command : commands) {
            String[] parts = command.trim().split("\\s+");
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
                    new TouchCommand().execute(arguments);
                    break;
                case "rmdir":
                    new TouchCommand().execute(arguments);
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
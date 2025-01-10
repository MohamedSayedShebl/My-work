import java.io.File;
public class MkdirCommand {
    public void execute(String[] args){
        String directoryName=args[0];
        if (directoryName.length()==0){
            System.out.println("mkdir takes a directory name as a parameter");
        }
        else{
            File newDirectory= new File(directoryName);
            if (!newDirectory.exists()){
                newDirectory.mkdir();
                System.out.println(directoryName+"directory has been created successfully");
            }
            else{
                System.out.println("the directory already exests");
            }
        }

    }
}




import java.io.File;

public class DirectoryContents2 {
    static void recursivePrint(File[] arr, int index, int level) {
        if (index == arr.length)
            return;

        for (int i = 0; i < level; i++)
            System.out.print("\t");

        if (arr[index].isFile())
            System.out.println(arr[index].getName());
        else if (arr[index].isDirectory()) {
            System.out.println("[" + arr[index].getName() + "]");
            recursivePrint(arr[index].listFiles(), 0, level + 1);
        }

        recursivePrint(arr, ++index, level);
    }

    public static void main(String[] args) {
        String mainDirPath = "E://javapgm//package1";
        File mainDir = new File(mainDirPath);

        if (mainDir.exists() && mainDir.isDirectory()) {
            File[] arr = mainDir.listFiles();
            System.out.println("**********************************************");
            System.out.println("Files from main directory: " + mainDir);
            System.out.println("**********************************************");
            recursivePrint(arr, 0, 0);
        }
    }
}

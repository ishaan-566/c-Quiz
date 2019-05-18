import java.io.File;
public class Mainn
{
  public static void main(String[] argv) throws Exception 
  {
	String s="";
	for(String j:argv)
	{
		s+=j;
	}
      deleteDir(new File(s));
  }

  public static boolean deleteDir(File dir) {
    if (dir.isDirectory()) //check if directory is present
    {
        String[] children = dir.list();//store all files and sub directories
        for (int i = 0; i < children.length; i++) 
        {
            boolean success = deleteDir(new File(dir, children[i]));
            if (!success)
            {
               return false;
            }
        }
    }
    return dir.delete();
  }
}
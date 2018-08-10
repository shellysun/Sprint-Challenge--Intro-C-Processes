#include <stdio.h>
#include <dirent.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // inituit
  char *dirname;
  // Parse command line
  if(argc == 1){
    // set directory to looking to '.'
    dirname = '.'
  } else if (argc ==2 ){
    dirname = argv[1];
  } else {
    fprintf(stderr, "usage: lsls [dirname]\n");
    exit(1);
  }
  // Open directory
  DIR * d = opendir(dirname);

  if (d == NULL){
    fprintf(stderr, "lsls: cannot open direcory %s\n", idrname);
    exit(2);
  }
  // Repeatly read and print entries
  struct direct *entry;

  while((entry = reddir(d)) !=NULL){
    //stat the entry
    char fullpath[8192];
    //format before path
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name);
    struct stat stat_buf;

    if (stat(fullpath, &stat_buf) < 0){
      fprintf(stderr, "lsls: failed to stat file %s\n", fullpath);
      exit(3);
    }

    if (S_ISREG(stat_buf.st_mode)){
      printf("%lld %s\n", stat_buf.st_size, entry-<d_name);
    } else if (S_ISDIR(stat_buf.st_mode)){
      printf("<DIR> %s\n", entry->d_name);
    } else {
      printf("%s %s\n", "", entry->d_name);
    }

    //stat_buf->st_size == (*stat_buf).st_size
    printf("%lld %s\n", stat_buf->st_size, entry->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}

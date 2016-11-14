int
main(int argc, char * argv[]) {
  int c = 0;

  char* exeName = nullptr;

  while ((c = getopt(argc, argv, "o:")) != -1) {
    switch (c) {
      case 'o':
        exeName = optarg;
        break;
      default:
        exit(0);
    }
  }
}

int main() {
  int *p;
  init(&p);
  printf("%d, %d",*(int*)(p+4),*(int*)(p+31));
  return 0;
}

#include <stdio.h>
void main() {
  char inputs[100], output[100];
  int c = 0, d = 0;
  printf("Enter some text:\n");
  gets(inputs);
  while (inputs[c] != '\0') {
    if (!(inputs[c] == ' ' && inputs[c + 1] == ' ')) {
      output[d] = inputs[c];
      d++;
    }
    c++;
  }
  output[d] = '\0';
  printf("Text after removing extra spaces:\n%s\n", output);
}
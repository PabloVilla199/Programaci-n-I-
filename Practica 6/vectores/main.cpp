#include <iostream>

using namespace std;

#include <iostream>

int main() {
  int v1[] = {1, 6, 8, 9};
  int v2[] = {2, 4, 6, 8};
  int vtot[10];

  int i = 0, j = 0, k = 0;

  while (i < 4 && j < 4) {
    if (v1[i] < v2[j]) {
      vtot[k++] = v1[i++];
    } else if (v1[i] > v2[j]) {
      vtot[k++] = v2[j++];
    } else {
      // Elementos iguales, puedes manejar esto como desees, en este caso se omiten.
      i++;
      j++;
    }
  }

  // Agregar los elementos restantes de v1 y v2 a vtot
  while (i < 4) {
    vtot[k++] = v1[i++];
  }
  while (j < 4) {
    vtot[k++] = v2[j++];
  }

  // Mostrar el resultado
  for (int l = 0; l < k; l++) {
    std::cout << vtot[l] << " ";
  }

  return 0;
}

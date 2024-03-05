#include <stdio.h>
#include <stdlib.h>
#include <FreeImage.h>

int contar_pixeles(const char *imagen_path)
{
    FIBITMAP *imagen;
    int ancho, alto;
    int total_pixeles = 0;

    // Cargar la imagen
    imagen = FreeImage_Load(FIF_JPEG, imagen_path, JPEG_DEFAULT);

    if (!imagen)
    {
        printf("No se pudo cargar la imagen.\n");
        return -1;
    }

    // Obtener las dimensiones de la imagen
    ancho = FreeImage_GetWidth(imagen);
    alto = FreeImage_GetHeight(imagen);

    // Iterar sobre cada píxel de la imagen
    for (int y = 0; y < alto; y++)
    {
        for (int x = 0; x < ancho; x++)
        {
            RGBQUAD color;
            FreeImage_GetPixelColor(imagen, x, y, &color);

            // Incrementar el contador de píxeles
            total_pixeles++;
        }
    }

    // Liberar la memoria de la imagen
    FreeImage_Unload(imagen);

    return total_pixeles;
}

int main()
{
    const char *ruta_imagen = "ruta/a/tu/imagen.jpg";
    int total_pixeles;

    // Contar píxeles
    total_pixeles = contar_pixeles(ruta_imagen);

    if (total_pixeles >= 0)
    {
        printf("La imagen tiene un total de %d pixeles.\n", total_pixeles);
    }

    return 0;
}

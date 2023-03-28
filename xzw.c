void drawLine(int x1, int y1, int x2, int y2, int width, unsigned char* image, int imageWidth, int imageHeight) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    int e2;
    int x = x1;
    int y = y1;
    int i, j;
    int halfWidth = width / 2;
    for (;;) {
        for (i = -halfWidth; i <= halfWidth; i++) {
            for (j = -halfWidth; j <= halfWidth; j++) {
                int px = x + i;
                int py = y + j;
                if (px >= 0 && px < imageWidth && py >= 0 && py < imageHeight) {
                    int index = (py * imageWidth + px) * 4;
                    image[index] = 255;
                    image[index + 1] = 0;
                    image[index + 2] = 0;
                    image[index + 3] = 255;
                }
            }
        }
        if (x == x2 && y == y2) {
            break;
        }
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

#include <stdlib.h>

#include "wayland-egl-priv.h"

WL_EXPORT struct wl_egl_window *
wl_egl_window_create(struct wl_surface *surface,
		     int width, int height)
{
	struct wl_egl_window *egl_window;

	egl_window = malloc(sizeof (*egl_window));
	if (!egl_window)
		return NULL;

	egl_window->surface = surface;
	egl_window->attached_width = 0;
	egl_window->attached_height = 0;

	wl_egl_window_resize(egl_window, width, height, 0, 0);

	return egl_window;
}

WL_EXPORT void
wl_egl_window_destroy(struct wl_egl_window *egl_window)
{
	free(egl_window);
}

WL_EXPORT void
wl_egl_window_resize(struct wl_egl_window *egl_window,
		     int width, int height,
		     int dx, int dy)
{
	egl_window->width = width;
	egl_window->height = height;
	egl_window->dx = dx;
	egl_window->dy = dy;
}

WL_EXPORT void
wl_egl_window_get_attached_size(struct wl_egl_window *egl_window,
				int *width, int *height)
{
	if (width)
		*width = egl_window->attached_width;
	if (height)
		*height = egl_window->attached_height;
}

WL_EXPORT struct wl_egl_pixmap *
wl_egl_pixmap_create(int width, int height, uint32_t flags)
{
	struct wl_egl_pixmap *egl_pixmap;

	egl_pixmap = malloc(sizeof (*egl_pixmap));
	if (!egl_pixmap)
		return NULL;

	egl_pixmap->width = width;
	egl_pixmap->height = height;
	egl_pixmap->flags = flags;

	return egl_pixmap;
}

WL_EXPORT void
wl_egl_pixmap_destroy(struct wl_egl_pixmap *egl_pixmap)
{
	free(egl_pixmap);
}

WL_EXPORT struct wl_buffer *
wl_egl_pixmap_create_buffer(struct wl_egl_pixmap *egl_pixmap)
{
	return egl_pixmap->buffer;
}

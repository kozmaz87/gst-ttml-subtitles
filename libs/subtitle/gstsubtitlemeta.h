/* GStreamer
 * Copyright (C) <2015> British Broadcasting Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_SUBTITLE_META_H__
#define __GST_SUBTITLE_META_H__

#include <gst/gst.h>
#include "gstsubtitle.h"

G_BEGIN_DECLS

typedef struct _GstSubtitleMeta GstSubtitleMeta;

/**
 * GstSubtitleMeta:
 * @meta: the parent #GstMeta.
 * @properties: the properties of the sample.
 * @crypto_info: the cryptographic information needed to decrypt the sample.
 *
 * Metadata type that holds information about a sample from a subtitle-protected
 * track, including the information needed to decrypt it (if it is encrypted).
 */
struct _GstSubtitleMeta {
  GstMeta meta;

  GPtrArray *areas;
};

GType gst_subtitle_meta_api_get_type (void);
#define GST_SUBTITLE_META_API_TYPE (gst_subtitle_meta_api_get_type())

#define gst_buffer_get_subtitle_meta(b) \
    ((GstSubtitleMeta*)gst_buffer_get_meta ((b), GST_SUBTITLE_META_API_TYPE))

#define GST_SUBTITLE_META_INFO (gst_subtitle_meta_get_info())

gboolean gst_subtitle_meta_init (GstMeta * meta, gpointer params,
    GstBuffer * buffer);

void gst_subtitle_meta_free (GstMeta * meta, GstBuffer * buffer);

const GstMetaInfo * gst_subtitle_meta_get_info (void);

GstSubtitleMeta * gst_buffer_add_subtitle_meta (GstBuffer * buffer,
    GPtrArray * areas);

G_END_DECLS

#endif /* __GST_SUBTITLE_META_H__ */

/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2009, Nokia

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

#ifndef __TRACKER_MINER_H__
#define __TRACKER_MINER_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define TRACKER_TYPE_MINER	   (tracker_miner_get_type())
#define TRACKER_MINER(o)	   (G_TYPE_CHECK_INSTANCE_CAST ((o), TRACKER_TYPE_MINER, TrackerMiner))
#define TRACKER_MINER_CLASS(c)     (G_TYPE_CHECK_CLASS_CAST ((c),    TRACKER_TYPE_MINER, TrackerMinerClass))
#define TRACKER_IS_MINER(o)	   (G_TYPE_CHECK_INSTANCE_TYPE ((o), TRACKER_TYPE_MINER))
#define TRACKER_IS_MINER_CLASS(c)  (G_TYPE_CHECK_CLASS_TYPE ((c),    TRACKER_TYPE_MINER))
#define TRACKER_MINER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o),  TRACKER_TYPE_MINER, TrackerMinerClass))

typedef struct TrackerMiner TrackerMiner;
typedef struct TrackerMinerClass TrackerMinerClass;
typedef struct TrackerMinerPrivate TrackerMinerPrivate;

struct TrackerMiner {
        GObject parent_instance;
        TrackerMinerPrivate *private;
};

struct TrackerMinerClass {
        GObjectClass parent_class;

        /* signals */
        void (* started) (TrackerMiner *miner);
        void (* stopped) (TrackerMiner *miner);

        void (* paused)  (TrackerMiner *miner);
        void (* resumed) (TrackerMiner *miner);

	void (* terminated) (TrackerMiner *miner);
};


GType    tracker_miner_get_type    (void) G_GNUC_CONST;

G_CONST_RETURN gchar *tracker_miner_get_name (TrackerMiner           *miner);
void                  tracker_miner_start    (TrackerMiner           *miner);


G_END_DECLS

#endif /* __TRACKER_MINER_H__ */

/*
   FSearch - A fast file search utility
   Copyright © 2020 Christian Boxdörfer

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.
   */

#pragma once

#include "fsearch_array.h"
#include "fsearch_database.h"
#include "fsearch_db_entry.h"
#include "fsearch_filter.h"
#include "fsearch_query.h"
#include "fsearch_task.h"

#include <gio/gio.h>
#include <stdint.h>

typedef struct _DatabaseSearchResult {
    DynamicArray *entries;
    DynamicArray *files;
    DynamicArray *folders;
    uint32_t num_folders;
    uint32_t num_files;

    FsearchQuery *query;
} DatabaseSearchResult;

uint32_t
db_search_result_get_num_entries(DatabaseSearchResult *result);

uint32_t
db_search_result_get_num_files(DatabaseSearchResult *result);

uint32_t
db_search_result_get_num_folders(DatabaseSearchResult *result);

FsearchQuery *
db_search_result_get_query(DatabaseSearchResult *result);

const char *
db_search_result_get_name(DatabaseSearchResult *result, uint32_t pos);

void
db_search_result_init_path(DatabaseSearchResult *result, uint32_t pos, char *path, size_t path_len);

GString *
db_search_result_get_path(DatabaseSearchResult *result, uint32_t pos);

FsearchDatabaseEntryType
db_search_result_get_type(DatabaseSearchResult *result, uint32_t pos);

off_t
db_search_result_get_size(DatabaseSearchResult *result, uint32_t pos);

void *
db_search_result_get_entry(DatabaseSearchResult *result, uint32_t pos);

void
db_search_result_free(DatabaseSearchResult *result);

void
db_search_queue(FsearchTaskQueue *queue,
                FsearchQuery *query,
                FsearchTaskFinishedFunc finished_func,
                FsearchTaskCancelledFunc cancelled_func);

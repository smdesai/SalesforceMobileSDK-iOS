// @generated SignedSource<<deadbeef8badf00ddefec8edfacefeed>>

#include "smartstoreperf.h"

#pragma clang diagnostic ignored "-Wbitwise-op-parentheses"
#pragma clang diagnostic ignored "-Wshift-op-parentheses"
#pragma clang diagnostic ignored "-Wlogical-not-parentheses"
#pragma clang diagnostic ignored "-Wliteral-conversion"
extern CQL_WARN_UNUSED cql_code dump_perf(sqlite3 *_Nonnull _db_, sqlite3_stmt *_Nullable *_Nonnull _result_);
extern CQL_WARN_UNUSED cql_code dump_perf_average(sqlite3 *_Nonnull _db_, sqlite3_stmt *_Nullable *_Nonnull _result_);

// Generated from perf.sql:11

/*
CREATE PROC create_perf_table ()
BEGIN
  CREATE TABLE IF NOT EXISTS perf(
    time LONG_INT NOT NULL,
    marker TEXT NOT NULL,
    payload_size INTEGER NOT NULL,
    duration INTEGER NOT NULL,
    free_memory LONG_INT NOT NULL
  );
  CREATE INDEX IF NOT EXISTS idx_time ON perf (time);
END;
*/

#undef _PROC_
#define _PROC_ "create_perf_table"
CQL_WARN_UNUSED cql_code create_perf_table(sqlite3 *_Nonnull _db_) {
  cql_code _rc_ = SQLITE_OK;
  _rc_ = cql_exec(_db_,
    "CREATE TABLE IF NOT EXISTS perf( "
      "time LONG_INT NOT NULL, "
      "marker TEXT NOT NULL, "
      "payload_size INTEGER NOT NULL, "
      "duration INTEGER NOT NULL, "
      "free_memory LONG_INT NOT NULL "
    ")");
  if (_rc_ != SQLITE_OK) { cql_error_trace(); goto cql_cleanup; }
  _rc_ = cql_exec(_db_,
    "CREATE INDEX IF NOT EXISTS idx_time ON perf (time)");
  if (_rc_ != SQLITE_OK) { cql_error_trace(); goto cql_cleanup; }
  _rc_ = SQLITE_OK;

cql_cleanup:
  return _rc_;
}

// Generated from perf.sql:16

/*
CREATE PROC reset_perf_table ()
BEGIN
  DELETE FROM perf;
END;
*/

#undef _PROC_
#define _PROC_ "reset_perf_table"
CQL_WARN_UNUSED cql_code reset_perf_table(sqlite3 *_Nonnull _db_) {
  cql_code _rc_ = SQLITE_OK;
  _rc_ = cql_exec(_db_,
    "DELETE FROM perf");
  if (_rc_ != SQLITE_OK) { cql_error_trace(); goto cql_cleanup; }
  _rc_ = SQLITE_OK;

cql_cleanup:
  return _rc_;
}

// Generated from perf.sql:26

/*
CREATE PROC add_marker (time_ LONG_INT NOT NULL, marker_ TEXT NOT NULL, payload_size_ INTEGER NOT NULL, duration_ INTEGER NOT NULL, free_memory_ LONG_INT NOT NULL)
BEGIN
  INSERT INTO perf(time, marker, payload_size, duration, free_memory) VALUES(time_, marker_, payload_size_, duration_, free_memory_);
END;
*/

#undef _PROC_
#define _PROC_ "add_marker"
CQL_WARN_UNUSED cql_code add_marker(sqlite3 *_Nonnull _db_, cql_int64 time_, cql_string_ref _Nonnull marker_, cql_int32 payload_size_, cql_int32 duration_, cql_int64 free_memory_) {
  cql_code _rc_ = SQLITE_OK;
  sqlite3_stmt *_temp_stmt = NULL;

  _rc_ = cql_prepare(_db_, &_temp_stmt,
    "INSERT INTO perf(time, marker, payload_size, duration, free_memory) VALUES(?, ?, ?, ?, ?)");
  cql_multibind(&_rc_, _db_, &_temp_stmt, 5,
                CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT64, time_,
                CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_STRING, marker_,
                CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT32, payload_size_,
                CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT32, duration_,
                CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT64, free_memory_);
  if (_rc_ != SQLITE_OK) { cql_error_trace(); goto cql_cleanup; }
  _rc_ = sqlite3_step(_temp_stmt);
  if (_rc_ != SQLITE_DONE) { cql_error_trace(); goto cql_cleanup; }
  cql_finalize_stmt(&_temp_stmt);
  _rc_ = SQLITE_OK;

cql_cleanup:
  cql_finalize_stmt(&_temp_stmt);
  return _rc_;
}

// Generated from perf.sql:37

/*
CREATE PROC print_perf ()
BEGIN
  DECLARE C CURSOR FOR SELECT *
    FROM perf
  ORDER BY time ASC;
  LOOP FETCH C
  BEGIN
    CALL printf("%lld,%s,%d,%d,%lld\n", C.time, C.marker, C.payload_size, C.duration, C.free_memory);
  END;
  CLOSE C;
END;
*/

#undef _PROC_
#define _PROC_ "print_perf"

typedef struct print_perf_C_row {
  cql_bool _has_row_;
  cql_uint16 _refs_count_;
  cql_uint16 _refs_offset_;
  cql_int64 time;
  cql_int32 payload_size;
  cql_int32 duration;
  cql_int64 free_memory;
  cql_string_ref _Nonnull marker;
} print_perf_C_row;

#define print_perf_C_refs_offset cql_offsetof(print_perf_C_row, marker) // count = 1
CQL_WARN_UNUSED cql_code print_perf(sqlite3 *_Nonnull _db_) {
  cql_code _rc_ = SQLITE_OK;
  sqlite3_stmt *C = NULL;
  print_perf_C_row C_ = { ._refs_count_ = 1, ._refs_offset_ = print_perf_C_refs_offset };

  _rc_ = cql_prepare(_db_, &C,
    "SELECT time, marker, payload_size, duration, free_memory "
      "FROM perf "
    "ORDER BY time ASC");
  if (_rc_ != SQLITE_OK) { cql_error_trace(); goto cql_cleanup; }
  for (;;) {
    _rc_ = sqlite3_step(C);
    C_._has_row_ = _rc_ == SQLITE_ROW;
    cql_multifetch(_rc_, C, 5,
                   CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT64, &C_.time,
                   CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_STRING, &C_.marker,
                   CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT32, &C_.payload_size,
                   CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT32, &C_.duration,
                   CQL_DATA_TYPE_NOT_NULL | CQL_DATA_TYPE_INT64, &C_.free_memory);
    if (_rc_ != SQLITE_ROW && _rc_ != SQLITE_DONE) { cql_error_trace(); goto cql_cleanup; }
    if (!C_._has_row_) break;
    cql_alloc_cstr(_cstr_1, C_.marker);
    printf("%lld,%s,%d,%d,%lld\n", C_.time, _cstr_1, C_.payload_size, C_.duration, C_.free_memory);
    cql_free_cstr(_cstr_1, C_.marker);
  }
  cql_finalize_stmt(&C);
  _rc_ = SQLITE_OK;

cql_cleanup:
  cql_finalize_stmt(&C);
  cql_teardown_row(C_);
  return _rc_;
}

// Generated from perf.sql:42

/*
CREATE PROC dump_perf ()
BEGIN
  SELECT *
    FROM perf
  ORDER BY time ASC;
END;
*/

#undef _PROC_
#define _PROC_ "dump_perf"
static int32_t dump_perf_perf_index;

cql_string_literal(dump_perf_stored_procedure_name, "dump_perf");

typedef struct dump_perf_row {
  cql_int64 time;
  cql_int32 payload_size;
  cql_int32 duration;
  cql_int64 free_memory;
  cql_string_ref _Nonnull marker;
} dump_perf_row;

cql_int64 dump_perf_get_time(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_row *data = (dump_perf_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].time;
}

cql_string_ref _Nonnull dump_perf_get_marker(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_row *data = (dump_perf_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].marker;
}

cql_int32 dump_perf_get_payload_size(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_row *data = (dump_perf_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].payload_size;
}

cql_int32 dump_perf_get_duration(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_row *data = (dump_perf_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].duration;
}

cql_int64 dump_perf_get_free_memory(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_row *data = (dump_perf_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].free_memory;
}

uint8_t dump_perf_data_types[dump_perf_data_types_count] = {
  CQL_DATA_TYPE_INT64 | CQL_DATA_TYPE_NOT_NULL, // time
  CQL_DATA_TYPE_STRING | CQL_DATA_TYPE_NOT_NULL, // marker
  CQL_DATA_TYPE_INT32 | CQL_DATA_TYPE_NOT_NULL, // payload_size
  CQL_DATA_TYPE_INT32 | CQL_DATA_TYPE_NOT_NULL, // duration
  CQL_DATA_TYPE_INT64 | CQL_DATA_TYPE_NOT_NULL, // free_memory
};

#define dump_perf_refs_offset cql_offsetof(dump_perf_row, marker) // count = 1

static cql_uint16 dump_perf_col_offsets[] = { 5,
  cql_offsetof(dump_perf_row, time),
  cql_offsetof(dump_perf_row, marker),
  cql_offsetof(dump_perf_row, payload_size),
  cql_offsetof(dump_perf_row, duration),
  cql_offsetof(dump_perf_row, free_memory)
};

cql_int32 dump_perf_result_count(dump_perf_result_set_ref _Nonnull result_set) {
  return cql_result_set_get_count((cql_result_set_ref)result_set);
}

CQL_WARN_UNUSED cql_code dump_perf_fetch_results(sqlite3 *_Nonnull _db_, dump_perf_result_set_ref _Nullable *_Nonnull result_set) {
  sqlite3_stmt *stmt = NULL;
  cql_profile_start(CRC_dump_perf, &dump_perf_perf_index);
  cql_code rc = dump_perf(_db_, &stmt);
  cql_fetch_info info = {
    .rc = rc,
    .db = _db_,
    .stmt = stmt,
    .data_types = dump_perf_data_types,
    .col_offsets = dump_perf_col_offsets,
    .refs_count = 1,
    .refs_offset = dump_perf_refs_offset,
    .rowsize = sizeof(dump_perf_row),
    .crc = CRC_dump_perf,
    .perf_index = &dump_perf_perf_index,
  };
  return cql_fetch_all_results(&info, (cql_result_set_ref *)result_set);
}

CQL_WARN_UNUSED cql_code dump_perf(sqlite3 *_Nonnull _db_, sqlite3_stmt *_Nullable *_Nonnull _result_) {
  cql_code _rc_ = SQLITE_OK;
  *_result_ = NULL;
  _rc_ = cql_prepare(_db_, _result_,
    "SELECT time, marker, payload_size, duration, free_memory "
      "FROM perf "
    "ORDER BY time ASC");
  if (_rc_ != SQLITE_OK) { cql_error_trace(); goto cql_cleanup; }
  _rc_ = SQLITE_OK;

cql_cleanup:
  if (_rc_ == SQLITE_OK && !*_result_) _rc_ = SQLITE_ERROR;
  return _rc_;
}

// Generated from perf.sql:47

/*
CREATE PROC dump_perf_average ()
BEGIN
  SELECT time, marker, payload_size, avg(duration), avg(free_memory)
    FROM perf
    GROUP BY marker, payload_size
  ORDER BY time ASC;
END;
*/

#undef _PROC_
#define _PROC_ "dump_perf_average"
static int32_t dump_perf_average_perf_index;

cql_string_literal(dump_perf_average_stored_procedure_name, "dump_perf_average");

typedef struct dump_perf_average_row {
  cql_int64 time;
  cql_int32 payload_size;
  cql_nullable_double duration;
  cql_nullable_double free_memory;
  cql_string_ref _Nonnull marker;
} dump_perf_average_row;

cql_int64 dump_perf_average_get_time(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_average_row *data = (dump_perf_average_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].time;
}

cql_string_ref _Nonnull dump_perf_average_get_marker(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_average_row *data = (dump_perf_average_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].marker;
}

cql_int32 dump_perf_average_get_payload_size(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_average_row *data = (dump_perf_average_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].payload_size;
}

cql_bool dump_perf_average_get_duration_is_null(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_average_row *data = (dump_perf_average_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].duration.is_null;
}

cql_double dump_perf_average_get_duration_value(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_average_row *data = (dump_perf_average_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].duration.value;
}

cql_bool dump_perf_average_get_free_memory_is_null(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_average_row *data = (dump_perf_average_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].free_memory.is_null;
}

cql_double dump_perf_average_get_free_memory_value(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row) {
  dump_perf_average_row *data = (dump_perf_average_row *)cql_result_set_get_data((cql_result_set_ref)result_set);
  return data[row].free_memory.value;
}

uint8_t dump_perf_average_data_types[dump_perf_average_data_types_count] = {
  CQL_DATA_TYPE_INT64 | CQL_DATA_TYPE_NOT_NULL, // time
  CQL_DATA_TYPE_STRING | CQL_DATA_TYPE_NOT_NULL, // marker
  CQL_DATA_TYPE_INT32 | CQL_DATA_TYPE_NOT_NULL, // payload_size
  CQL_DATA_TYPE_DOUBLE, // duration
  CQL_DATA_TYPE_DOUBLE, // free_memory
};

#define dump_perf_average_refs_offset cql_offsetof(dump_perf_average_row, marker) // count = 1

static cql_uint16 dump_perf_average_col_offsets[] = { 5,
  cql_offsetof(dump_perf_average_row, time),
  cql_offsetof(dump_perf_average_row, marker),
  cql_offsetof(dump_perf_average_row, payload_size),
  cql_offsetof(dump_perf_average_row, duration),
  cql_offsetof(dump_perf_average_row, free_memory)
};

cql_int32 dump_perf_average_result_count(dump_perf_average_result_set_ref _Nonnull result_set) {
  return cql_result_set_get_count((cql_result_set_ref)result_set);
}

CQL_WARN_UNUSED cql_code dump_perf_average_fetch_results(sqlite3 *_Nonnull _db_, dump_perf_average_result_set_ref _Nullable *_Nonnull result_set) {
  sqlite3_stmt *stmt = NULL;
  cql_profile_start(CRC_dump_perf_average, &dump_perf_average_perf_index);
  cql_code rc = dump_perf_average(_db_, &stmt);
  cql_fetch_info info = {
    .rc = rc,
    .db = _db_,
    .stmt = stmt,
    .data_types = dump_perf_average_data_types,
    .col_offsets = dump_perf_average_col_offsets,
    .refs_count = 1,
    .refs_offset = dump_perf_average_refs_offset,
    .rowsize = sizeof(dump_perf_average_row),
    .crc = CRC_dump_perf_average,
    .perf_index = &dump_perf_average_perf_index,
  };
  return cql_fetch_all_results(&info, (cql_result_set_ref *)result_set);
}

CQL_WARN_UNUSED cql_code dump_perf_average(sqlite3 *_Nonnull _db_, sqlite3_stmt *_Nullable *_Nonnull _result_) {
  cql_code _rc_ = SQLITE_OK;
  *_result_ = NULL;
  _rc_ = cql_prepare(_db_, _result_,
    "SELECT time, marker, payload_size, avg(duration), avg(free_memory) "
      "FROM perf "
      "GROUP BY marker, payload_size "
    "ORDER BY time ASC");
  if (_rc_ != SQLITE_OK) { cql_error_trace(); goto cql_cleanup; }
  _rc_ = SQLITE_OK;

cql_cleanup:
  if (_rc_ == SQLITE_OK && !*_result_) _rc_ = SQLITE_ERROR;
  return _rc_;
}

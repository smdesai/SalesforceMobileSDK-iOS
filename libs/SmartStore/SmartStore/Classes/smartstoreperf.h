// @generated SignedSource<<deadbeef8badf00ddefec8edfacefeed>>
#pragma once

#include "cqlrt.h"


// Generated from smartstoreperf.sql:12
extern CQL_WARN_UNUSED cql_code create_perf_table(sqlite3 *_Nonnull _db_);

// Generated from smartstoreperf.sql:17
extern CQL_WARN_UNUSED cql_code reset_perf_table(sqlite3 *_Nonnull _db_);

// Generated from smartstoreperf.sql:31
extern CQL_WARN_UNUSED cql_code add_marker(sqlite3 *_Nonnull _db_, cql_int64 time_, cql_string_ref _Nonnull marker_, cql_int32 payload_size_, cql_int32 duration_, cql_int64 memory_used_, cql_int32 upsert_returns_);

// Generated from smartstoreperf.sql:43
extern CQL_WARN_UNUSED cql_code print_perf(sqlite3 *_Nonnull _db_);

// Generated from smartstoreperf.sql:48
#define CRC_dump_perf 6475687019409639779L

extern cql_string_ref _Nonnull dump_perf_stored_procedure_name;

#define dump_perf_data_types_count 6

cql_result_set_type_decl(dump_perf_result_set, dump_perf_result_set_ref);
extern cql_int64 dump_perf_get_time(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_string_ref _Nonnull dump_perf_get_marker(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_get_payload_size(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_get_duration(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int64 dump_perf_get_memory_used(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_get_upsert_returns(dump_perf_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_result_count(dump_perf_result_set_ref _Nonnull result_set);
extern CQL_WARN_UNUSED cql_code dump_perf_fetch_results(sqlite3 *_Nonnull _db_, dump_perf_result_set_ref _Nullable *_Nonnull result_set);
#define dump_perf_row_hash(result_set, row) cql_result_set_get_meta((cql_result_set_ref)(result_set))->rowHash((cql_result_set_ref)(result_set), row)
#define dump_perf_row_equal(rs1, row1, rs2, row2) \
cql_result_set_get_meta((cql_result_set_ref)(rs1))->rowsEqual( \
  (cql_result_set_ref)(rs1), \
  row1, \
  (cql_result_set_ref)(rs2), \
  row2)

// Generated from smartstoreperf.sql:55
#define CRC_dump_perf_average 516379200630615018L

extern cql_string_ref _Nonnull dump_perf_average_stored_procedure_name;

#define dump_perf_average_data_types_count 6

cql_result_set_type_decl(dump_perf_average_result_set, dump_perf_average_result_set_ref);
extern cql_int64 dump_perf_average_get_time(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_string_ref _Nonnull dump_perf_average_get_marker(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_average_get_payload_size(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_bool dump_perf_average_get_duration_is_null(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_double dump_perf_average_get_duration_value(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int64 dump_perf_average_get_memory_used(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_average_get_upsert_returns(dump_perf_average_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_average_result_count(dump_perf_average_result_set_ref _Nonnull result_set);
extern CQL_WARN_UNUSED cql_code dump_perf_average_fetch_results(sqlite3 *_Nonnull _db_, dump_perf_average_result_set_ref _Nullable *_Nonnull result_set);
#define dump_perf_average_row_hash(result_set, row) cql_result_set_get_meta((cql_result_set_ref)(result_set))->rowHash((cql_result_set_ref)(result_set), row)
#define dump_perf_average_row_equal(rs1, row1, rs2, row2) \
cql_result_set_get_meta((cql_result_set_ref)(rs1))->rowsEqual( \
  (cql_result_set_ref)(rs1), \
  row1, \
  (cql_result_set_ref)(rs2), \
  row2)

// Generated from smartstoreperf.sql:63
#define CRC_dump_perf_memory_delta -2033058614710539756L

extern cql_string_ref _Nonnull dump_perf_memory_delta_stored_procedure_name;

#define dump_perf_memory_delta_data_types_count 6

cql_result_set_type_decl(dump_perf_memory_delta_result_set, dump_perf_memory_delta_result_set_ref);
extern cql_int64 dump_perf_memory_delta_get_time(dump_perf_memory_delta_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_string_ref _Nonnull dump_perf_memory_delta_get_marker(dump_perf_memory_delta_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_memory_delta_get_payload_size(dump_perf_memory_delta_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_memory_delta_get_duration(dump_perf_memory_delta_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_bool dump_perf_memory_delta_get_memory_delta_is_null(dump_perf_memory_delta_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int64 dump_perf_memory_delta_get_memory_delta_value(dump_perf_memory_delta_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_memory_delta_get_upsert_returns(dump_perf_memory_delta_result_set_ref _Nonnull result_set, cql_int32 row);
extern cql_int32 dump_perf_memory_delta_result_count(dump_perf_memory_delta_result_set_ref _Nonnull result_set);
extern CQL_WARN_UNUSED cql_code dump_perf_memory_delta_fetch_results(sqlite3 *_Nonnull _db_, dump_perf_memory_delta_result_set_ref _Nullable *_Nonnull result_set);
#define dump_perf_memory_delta_row_hash(result_set, row) cql_result_set_get_meta((cql_result_set_ref)(result_set))->rowHash((cql_result_set_ref)(result_set), row)
#define dump_perf_memory_delta_row_equal(rs1, row1, rs2, row2) \
cql_result_set_get_meta((cql_result_set_ref)(rs1))->rowsEqual( \
  (cql_result_set_ref)(rs1), \
  row1, \
  (cql_result_set_ref)(rs2), \
  row2)

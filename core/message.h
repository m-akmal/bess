#ifndef BESS_MESSAGE_H_
#define BESS_MESSAGE_H_

#include <cstdarg>

#include "bess_msg.pb.h"
#include "error.pb.h"

typedef bess::pb::Error pb_error_t;
typedef bess::pb::ModuleCommandResponse pb_cmd_response_t;

template <typename T, typename M, typename A>
using pb_func_t = std::function<T(M *, const A &)>;

[[gnu::format(printf, 2, 3)]] pb_error_t pb_error(int code, const char *fmt,
                                                  ...);

static inline pb_error_t pb_errno(int code) {
  return pb_error(code, "%s", strerror(code));
}

#endif  // BESS_MESSAGE_H_

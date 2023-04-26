#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 16
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_LF = 1,
  aux_sym_user_input_content_token1 = 2,
  sym_prompt_tag = 3,
  sym_continue_prompt_tag = 4,
  sym_source_file = 5,
  sym_entry = 6,
  sym_prompt = 7,
  sym_user_input = 8,
  sym__followup_statement = 9,
  sym_user_input_statement = 10,
  sym_user_input_content = 11,
  sym_output = 12,
  sym_output_content = 13,
  aux_sym_source_file_repeat1 = 14,
  aux_sym_user_input_repeat1 = 15,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [aux_sym_user_input_content_token1] = "user_input_content_token1",
  [sym_prompt_tag] = "prompt_tag",
  [sym_continue_prompt_tag] = "continue_prompt_tag",
  [sym_source_file] = "source_file",
  [sym_entry] = "entry",
  [sym_prompt] = "prompt",
  [sym_user_input] = "user_input",
  [sym__followup_statement] = "_followup_statement",
  [sym_user_input_statement] = "user_input_statement",
  [sym_user_input_content] = "user_input_content",
  [sym_output] = "output",
  [sym_output_content] = "output_content",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_user_input_repeat1] = "user_input_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [aux_sym_user_input_content_token1] = aux_sym_user_input_content_token1,
  [sym_prompt_tag] = sym_prompt_tag,
  [sym_continue_prompt_tag] = sym_continue_prompt_tag,
  [sym_source_file] = sym_source_file,
  [sym_entry] = sym_entry,
  [sym_prompt] = sym_prompt,
  [sym_user_input] = sym_user_input,
  [sym__followup_statement] = sym__followup_statement,
  [sym_user_input_statement] = sym_user_input_statement,
  [sym_user_input_content] = sym_user_input_content,
  [sym_output] = sym_output,
  [sym_output_content] = sym_output_content,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_user_input_repeat1] = aux_sym_user_input_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_user_input_content_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_prompt_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_continue_prompt_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_entry] = {
    .visible = true,
    .named = true,
  },
  [sym_prompt] = {
    .visible = true,
    .named = true,
  },
  [sym_user_input] = {
    .visible = true,
    .named = true,
  },
  [sym__followup_statement] = {
    .visible = false,
    .named = true,
  },
  [sym_user_input_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_user_input_content] = {
    .visible = true,
    .named = true,
  },
  [sym_output] = {
    .visible = true,
    .named = true,
  },
  [sym_output_content] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_user_input_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'd') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (eof) ADVANCE(4);
      if (lookahead == '\n') SKIP(3)
      if (lookahead == 'd') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(7);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(6);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == '\n') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == 'd') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == '.') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == '>') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == '>') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == 'a') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == 'd') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead == 'p') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_user_input_content_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_prompt_tag);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_continue_prompt_tag);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 3},
  [2] = {.lex_state = 3},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_user_input_content_token1] = ACTIONS(1),
    [sym_prompt_tag] = ACTIONS(1),
    [sym_continue_prompt_tag] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(16),
    [sym_entry] = STATE(2),
    [sym_prompt] = STATE(12),
    [sym_output] = STATE(12),
    [sym_output_content] = STATE(17),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_user_input_content_token1] = ACTIONS(5),
    [sym_prompt_tag] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(5), 1,
      aux_sym_user_input_content_token1,
    ACTIONS(7), 1,
      sym_prompt_tag,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    STATE(17), 1,
      sym_output_content,
    STATE(3), 2,
      sym_entry,
      aux_sym_source_file_repeat1,
    STATE(12), 2,
      sym_prompt,
      sym_output,
  [21] = 6,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      aux_sym_user_input_content_token1,
    ACTIONS(16), 1,
      sym_prompt_tag,
    STATE(17), 1,
      sym_output_content,
    STATE(3), 2,
      sym_entry,
      aux_sym_source_file_repeat1,
    STATE(12), 2,
      sym_prompt,
      sym_output,
  [42] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      sym_continue_prompt_tag,
    ACTIONS(21), 2,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
    STATE(5), 2,
      sym__followup_statement,
      aux_sym_user_input_repeat1,
  [57] = 4,
    ACTIONS(23), 1,
      sym_continue_prompt_tag,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 2,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
    STATE(6), 2,
      sym__followup_statement,
      aux_sym_user_input_repeat1,
  [72] = 4,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      sym_continue_prompt_tag,
    ACTIONS(31), 2,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
    STATE(6), 2,
      sym__followup_statement,
      aux_sym_user_input_repeat1,
  [87] = 5,
    ACTIONS(36), 1,
      anon_sym_LF,
    ACTIONS(38), 1,
      aux_sym_user_input_content_token1,
    STATE(4), 1,
      sym_user_input_statement,
    STATE(13), 1,
      sym_user_input,
    STATE(19), 1,
      sym_user_input_content,
  [103] = 2,
    ACTIONS(40), 1,
      ts_builtin_sym_end,
    ACTIONS(42), 3,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
      sym_continue_prompt_tag,
  [112] = 4,
    ACTIONS(36), 1,
      anon_sym_LF,
    ACTIONS(38), 1,
      aux_sym_user_input_content_token1,
    STATE(11), 1,
      sym_user_input_statement,
    STATE(19), 1,
      sym_user_input_content,
  [125] = 2,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(46), 3,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
      sym_continue_prompt_tag,
  [134] = 2,
    ACTIONS(48), 1,
      ts_builtin_sym_end,
    ACTIONS(50), 3,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
      sym_continue_prompt_tag,
  [143] = 2,
    ACTIONS(52), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 2,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
  [151] = 2,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    ACTIONS(58), 2,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
  [159] = 2,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
    ACTIONS(62), 2,
      aux_sym_user_input_content_token1,
      sym_prompt_tag,
  [167] = 1,
    ACTIONS(64), 1,
      anon_sym_LF,
  [171] = 1,
    ACTIONS(66), 1,
      ts_builtin_sym_end,
  [175] = 1,
    ACTIONS(68), 1,
      anon_sym_LF,
  [179] = 1,
    ACTIONS(70), 1,
      anon_sym_LF,
  [183] = 1,
    ACTIONS(72), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 21,
  [SMALL_STATE(4)] = 42,
  [SMALL_STATE(5)] = 57,
  [SMALL_STATE(6)] = 72,
  [SMALL_STATE(7)] = 87,
  [SMALL_STATE(8)] = 103,
  [SMALL_STATE(9)] = 112,
  [SMALL_STATE(10)] = 125,
  [SMALL_STATE(11)] = 134,
  [SMALL_STATE(12)] = 143,
  [SMALL_STATE(13)] = 151,
  [SMALL_STATE(14)] = 159,
  [SMALL_STATE(15)] = 167,
  [SMALL_STATE(16)] = 171,
  [SMALL_STATE(17)] = 175,
  [SMALL_STATE(18)] = 179,
  [SMALL_STATE(19)] = 183,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(15),
  [16] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_input, 1),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_user_input, 1),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_input, 2),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_user_input, 2),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_user_input_repeat1, 2),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_user_input_repeat1, 2),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_user_input_repeat1, 2), SHIFT_REPEAT(9),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [38] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_input_statement, 1),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_user_input_statement, 1),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_input_statement, 2),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_user_input_statement, 2),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__followup_statement, 2),
  [50] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__followup_statement, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entry, 1),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entry, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prompt, 2),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prompt, 2),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_output, 2),
  [62] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_output, 2),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_output_content, 1),
  [66] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_user_input_content, 1),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_dap_repl(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif

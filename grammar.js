module.exports = grammar({
  name: 'dap_repl',

  rules: {
    source_file: $ => repeat($.entry),

    entry: $ => choice(
      $.prompt,
      $.output,
    ),


    prompt: $ => seq($.prompt_tag, $.user_input),

    user_input: $ => seq($.user_input_statement, repeat($._followup_statement)),

    _followup_statement: $ => seq($.continue_prompt_tag, $.user_input_statement),
    user_input_statement: $ => seq(optional($.user_input_content), '\n'),
    user_input_content: $ => /.+/,

    prompt_tag: $ => token(prec(1, 'dap>')),
    continue_prompt_tag: $ =>token(prec(1, '...>')),


    output: $ => seq($.output_content, '\n'),
    output_content: $ => token(/.+/),
  }
});

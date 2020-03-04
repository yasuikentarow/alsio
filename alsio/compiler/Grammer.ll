defKlass:
  'class' tokenKlass defKlassBlock -> defKlass($2, $3)
  ;

defKlassBlock:
  '{' defKlassStatement* '}' -> defKlassBlock($2)
  ;

defKlassStatement:
  tokenKlass tokenVar initializer? -> defKlassVar($2, $3, $1)
  tokenVar initializer -> defKlassVar($1, $2)
  'func' tokenFunc ':' lambda -> defFunc($2, $4)
  'def' tokenFunc ':' lambda -> defMethod($2, $4)
  ;

initializer:
  '=' expr -> $2
  ;

lambda:
  tokenKlass '(' params ')' block -> onLambda($1, $3, $5)
  ;

block:
  '{' statements* blockEnd? '}' -> onBlock($2, $3)
  ;

blockEnd:
  'return' expr -> onBlockReturn($2);
  'break' -> onBlockBreak();
  'redo' -> onBlockRedo();
  ;

tokenKlass:
  /[
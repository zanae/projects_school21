#!/bin/bash
FAILS=0
SUCCESSES=0

diff_func() {
  local f=$1 # flags
  local t=$2 # text
  DIFF=$(diff <(grep $f $t) <(./s21_grep $f $t))
  #VALG=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log.txt ./s21_grep $f $t && grep "ERROR SUMMARY: 0 errors from 0 contexts" log.txt)
  if [ -z "$DIFF" ] #&& [ -n "$VALG" ] # -z - проверка на пустую строку
  then
    SUCCESSES=$((SUCCESSES+1))
    echo "SUCCESS $SUCCESSES: $f $t"
  else
    FAILS=$((FAILS+1))
    echo "							FAIL $FAILS: $f $t"
	#echo "$VALG"
  fi
}

check_files() {
  local _f=$1
  for text in *.txt; do
    diff_func "-$_f" "$text"
  done
  all_texts=$(ls *.txt)
  diff_func "-$_f" "$all_texts"
  diff_func "-$_f" "doesntexist.txt"
}

combinations() {
  local str=$1
  local len=$2
  local result=()
  
  if [[ $len -eq 1 ]]; then
    result=($(echo "$str" | fold -w1))
  else
    for ((i = 0; i <= ${#str} - $len; i++)); do
      local prefix=${str:i:1}
      local suffixes=($(combinations "${str:i+1}" $((len - 1))))
      for s in "${suffixes[@]}"; do
        result+=("$prefix$s")
      done
    done
  fi
  
  echo "${result[@]}" #массив сочетаний длины len
}

flags="ivclnhso"
regs=()

regs[0]="-e '('" 
regs[1]="-e LOL"
regs[2]="-e '^[A-Za-z]*[\!\.\?]*$'"
regs[3]="-f reg.txt"
regs[4]="[0-9]"
regs[5]="ben*o"
regs[6]="-f doesntexist.txt" #ЖОПА

for k in $(seq 1 3); do
  combs=($(combinations "$flags" $k))
  for comb in "${combs[@]}"; do
    for reg in "${regs[@]}"; do
      check_files "$comb $reg"
    done
  done
done

check_files "-ignore-case --file reg.txt"
check_files "-file reg.txt --regexp benvolio"
check_files "-file reg.txt --invert-match --regexp '^[ComedianBlAck0-9]*$'"

NUM_ALL=$((FAILS+SUCCESSES))
echo "Number of tests: $NUM_ALL"
echo "Number of fails: $FAILS"
echo "Number of successes: $SUCCESSES"

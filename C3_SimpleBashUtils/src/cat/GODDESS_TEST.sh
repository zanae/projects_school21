FAILS=0
SUCCESSES=0

diff_func() {
  local f=$1 # flags
  local t=$2 # text
  DIFF=$(diff <(cat $f $t) <(./s21_cat $f $t))
  if [[ -z "$DIFF" ]]; then # -z - проверка на пустую строку
    SUCCESSES=$((SUCCESSES+1))
    echo "SUCCESS $SUCCESSES: $f $t"
  else
    FAILS=$((FAILS+1))
    echo "							FAIL $FAILS: $f $t"
  fi
}

check_files() {
  local _f=$1
  for text in *.txt; do
    diff_func "-$_f" "$text"
  done
  all_texts=$(ls *.txt)
  diff_func "-$_f" "$all_texts"
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
  
  echo "${result[@]}" # Возвращаем результат - массив сочетаний длины len
}

flags="benstvTE"

# Для каждой длины генерируем сочетания
for k in $(seq 1 ${#flags}); do
  combs=($(combinations "$flags" $k))
  for comb in "${combs[@]}"; do
    check_files "$comb"
  done
done

check_files "-number"
check_files "-number-nonblank"
check_files "-squeeze-blank"
check_files "-number --number-nonblank -stE"
check_files "-squeeze-blank --number-nonblank --number -E"

NUM_ALL=$((FAILS+SUCCESSES))
echo "Number of tests: $NUM_ALL"
echo "Number of fails: $FAILS"
echo "Number of successes: $SUCCESSES"

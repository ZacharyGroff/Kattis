fn main() {
  let input = get_input_line::<usize>().unwrap();
  let mut limit = input[0];
  if (input[1] / 2) + 1 > limit {
    limit = (input[1] / 2) + 1;
  }
  let words = get_words(limit);
  print!("{}", words.join(" "));
}

fn get_input_line<T: std::str::FromStr>() -> Result<Vec<T>, <T as std::str::FromStr>::Err> {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input);
  input.split_whitespace().map(|x| x.parse::<T>()).collect()
}

fn get_alphabet() -> Vec<char> {
  (b'a'..=b'z')
    .map(|c| c as char)
    .filter(|c| c.is_alphabetic())
    .collect::<Vec<_>>()
}

fn get_words(limit: usize) -> Vec<String> {
  let alphabet = get_alphabet();
  let mut words: Vec<String> = Vec::new();
  for i in 0..6 {
    for j in 0..26 {
      for k in 0..26 {
        for l in 0..26 {
          words.push(format!("{}{}{}{}", alphabet[i], alphabet[j], alphabet[k], alphabet[l]));
        }
      }
    }
  }

  words[0..limit].to_vec()
}

const VOWELS: [char; 5] = ['a', 'e', 'i', 'o', 'u'];

fn main() {
  let input = get_input();
  let result = decrypt_input(input);
  println!("{}", result.join(" "));
}

fn get_input() -> Vec<String> {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");

  input.split_whitespace().map(|x| x.to_string()).collect::<Vec<String>>()
}

fn decrypt_input(input: Vec<String>) -> Vec<String> {
  let mut decrypted_input: Vec<String> = Vec::new();
  for word in input {
    let mut decrypted_word: String = "".to_string();
    let mut to_skip = 0;
    for c in word.chars() {
      if to_skip > 0 {
        to_skip -= 1;
        continue;
      }

      decrypted_word += &(c.to_string());

      if VOWELS.contains(&c) {
        to_skip = 2;
      } 
    }

    decrypted_input.push(decrypted_word);
  }

  decrypted_input
}

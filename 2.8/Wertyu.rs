macro_rules! hashmap {
    ($( $key: expr => $val: expr ),*) => {{
         let mut map = ::std::collections::HashMap::new();
         $( map.insert($key, $val); )*
         map
    }}
}

fn main() {
  let map = get_map();
  loop {
    let raw_input = try_get_input_line();
    let input = raw_input.trim();
    if input == "" {
      break;
    }
    let result = transform_input(input.to_string(), &map);
    println!("{}", result);
  }
}

fn get_map() -> std::collections::HashMap<char, char> {
  hashmap!['1' => '`', '2' => '1', '3' => '2', '4' => '3', '5' => '4',
          '6' => '5', '7' => '6', '8' => '7', '9' => '8', '0' => '9',
          '-' => '0', '=' => '-', 'W' => 'Q', 'E' => 'W', 'R' => 'E',
          'T' => 'R', 'Y' => 'T', 'U' => 'Y', 'I' => 'U', 'O' => 'I',
          'P' => 'O', '[' => 'P', ']' => '[', '\\' => ']', 'S' => 'A',
          'D' => 'S', 'F' => 'D', 'G' => 'F', 'H' => 'G', 'J' => 'H',
          'K' => 'J', 'L' => 'K', ';' => 'L', '\'' => ';', 'X' => 'Z',
          'C' => 'X', 'V' => 'C', 'B' => 'V', 'N' => 'B', 'M' => 'N',
          ',' => 'M', '.' => ',', '/' => '.']
}

fn try_get_input_line() -> String {
  let mut input = String::new();
  match std::io::stdin().read_line(&mut input) {
    Ok(_) => return input,
    _ => return String::new(),
  }
}

fn transform_input(input: String, map: &std::collections::HashMap<char, char>) -> String {
  let mut output = String::new();
  for c in input.chars() {
    if c == ' ' {
      output += &c.to_string();
    } else {
      output += &map[&c].to_string();
    }
  }

  output
}

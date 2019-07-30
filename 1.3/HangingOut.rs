fn main() {
  let mut set: u32 = 1;
  loop {
    let len: u32 = get_set_length();
    if len == 0 {
      break;
    }
    let mut names: Vec<String> = get_set_names(len);
    names = sort_names(names);
    let (names1, names2) = split_names(names);
    let names = merge_names(names1, names2);
    print_set(names, set);
    set += 1;
  }
}

fn get_set_length() -> u32 {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  input.trim().parse().expect("wanted a number")
}

fn get_set_names(len: u32) -> Vec<String> {
  let mut names = Vec::new();
  for _ in 0..len {
    let name: String = get_set_name();
    names.push(name);
  }

  names
}

fn get_set_name() -> String {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input).expect("read line error");
  input.trim().to_string()
}

fn sort_names(mut names: Vec<String>) -> Vec<String> {
  //sort name array by length of name
  names.sort_by(|a, b| a.len().cmp(&b.len()));
  names
}

fn split_names(names: Vec<String>) -> (Vec<String>, Vec<String>){
  //alternate pushing names into 2 different arrays
  let mut names1 = Vec::new();
  let mut names2 = Vec::new();

  for i in 0..names.len() {
    if i % 2 == 0 {
      names1.push(names[i].clone());
    } else {
      names2.push(names[i].clone());
    }
  }

  (names1, names2)
}

fn merge_names(mut names1: Vec<String>, mut names2: Vec<String>) -> Vec<String> {
  //reverse second array and merge together
  names2.reverse();
  names1.append(&mut names2);
  names1
}

fn print_set(names: Vec<String>, set: u32) {
  println!("SET {}", set);
  for name in names {
    println!("{}", name);
  }
}

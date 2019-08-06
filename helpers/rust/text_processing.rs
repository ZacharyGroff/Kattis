mod text_processing {
  fn get_alphabet() -> Vec<char> {
    (b'a'..=b'z')
      .map(|c| c as char)
      .filter(|c| c.is_alphabetic())
      .collect::<Vec<_>>()
  }
}

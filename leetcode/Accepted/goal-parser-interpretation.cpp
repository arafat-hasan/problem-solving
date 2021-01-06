class Solution {
  public:
    string interpret(string command) {
      replaceAll(command, "()", "o");
      replaceAll(command, "(al)", "al");
      return command;
    }
  private:
    // Thanks to: https://stackoverflow.com/a/3418285/7829174
    void replaceAll(std::string& str, const std::string& from, const std::string& to) {
      if(from.empty())
        return;
      size_t start_pos = 0;
      while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
      }
    }
};

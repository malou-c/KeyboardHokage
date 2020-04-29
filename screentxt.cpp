#include "screentxt.hpp"

// constructors

TextWindow::TextWindow() {
  //загружаем спрайт окошечка
  font.loadFromFile("fonts/3976.ttf");
  texture.loadFromFile("images/text_window.png");
  sprite.setTexture(texture);
  setPosition(100, 100);
  //текст
  text_color = sf::Color::Black;
  font_size = 25;  // размер текста
  margin_y = 10;   // расстояние между строками
  start_str = 0;  // строка с которой начинается вывод
}

//функции
//меняет характеристики текста для вывода
void TextWindow::change_text_character() {
  sprite.setPosition(position.x, position.y);  // ставим окошко в  позицию
  //стираем все  что было ДО в  векторе
  for (int i = 0; i < vec_text.size(); i++) {
    vec_text[i].setString("");
  }
  vec_text.resize(
      count_text_string);  // меняем размер вектора = кол-ву строк в окошке

  std::cout << "razmer vec" << vec_text.size() << std::endl;
  std::cout << "razmer str" << text_str.size() << std::endl;
  for (int i = start_str, j = 0; i < text_str.size(); i++, j++) {
    if (i - start_str >= count_text_string || i >= text_str.size())
      break;  // условия остановки
    vec_text[j].setFont(font);
    vec_text[j].setFillColor(Color::Black);
    vec_text[j].setCharacterSize(font_size);
    vec_text[j].setPosition(getPosition().x + 20,
                            getPosition().y + ((margin_y + font_size) * j));
    vec_text[j].setString(text_str[i]);
  }
}

//рисуем текст внутри окна
void TextWindow::DrawTextWindow(RenderWindow &window) {
  window.draw(sprite);  // фон

  for (int i = 0; i < vec_text.size(); i++) {
    window.draw(vec_text[i]);
  }
}
//считаем сколько строк поместится в окно
void TextWindow::change_count_text_str() {
  std::cout << "text str size" << text_str.size() << std::endl;
  Text text_help("S", font, font_size);
  for (int i = 1; i <= text_str.size(); i++) {
    std::cout << (text_help.getLocalBounds().height + margin_y) * i
              << std::endl;
    if ((text_help.getLocalBounds().height + margin_y) * (i + 1) >
            sprite.getLocalBounds().height - (font_size * 2) ||
        i == text_str.size()) {
      count_text_string = i;
      break;
    }
  }
  std::cout << "text height" << text_help.getLocalBounds().height << std::endl;
}

void TextWindow::next_text_str() {
  start_str++;
  change_text_character();
}
void TextWindow::back_text_str() {
  start_str--;
  change_text_character();
}

//добовление слова в  текст
void TextWindow::add_word_in_text(std::vector<std::wstring> &text, Word word,
                                  int j)  //не тестированно
{
  text[j].append(word.get_word());
  text[j].push_back(L' ');
}
// конвертирование файла в вектор с текстом
std::vector<std::wstring> TextWindow::convert_file_to_text(
    std::string filename) {
  Text text_help("S", font, font_size);
  std::wstring str = readfile_to_wstr(filename);
  std::vector<std::wstring> text;
  Word word;

  text.resize(1);
  int j = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] != L' ') {
      word.add(str[i]);
    } else {
      if ((word.get_len() + text[j].size()) * text_help.getLocalBounds().width <
          sprite.getLocalBounds().width - 30) {
        add_word_in_text(text, word, j);
        word.clean();
      } else {
        j++;
        text.resize(j + 1);
        add_word_in_text(text, word, j);

        word.clean();
      }
    }
  }

  return text;
}

// setters
void TextWindow::setPosition(int x, int y) {
  position.x = x;
  position.y = y;
}
void TextWindow::setText(std::string filename) {
  text_str = convert_file_to_text(filename);
}

// getters
Vector2i TextWindow::getPosition() { return position; }

int main() {
  TextWindow txwin;
  txwin.setText("texts/text_1.txt");  // берем текст
  txwin.change_count_text_str();
  std::cout << txwin.count_text_string << std::endl;
  txwin.change_text_character();  // вычисляем характеристики текста

  //параметры окна
  int height = 950, width = 1500;
  ContextSettings settings;
  settings.antialiasingLevel = 8;
  RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default,
                      settings);

  window.clear(Color::White);
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Q)) {
      txwin.next_text_str();
    }
    int n = 0;
    // std::cin >> n;
    if (n == 1) {
      txwin.next_text_str();
    }
    txwin.DrawTextWindow(window);
    window.display();
  }

  return 0;
}
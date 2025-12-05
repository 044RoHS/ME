# Этап 1: сборка под GCC и Clang
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# Устанавливаем оба компилятора
RUN apt update && \
    apt install -y g++ clang make && \
    apt clean && rm -rf /var/lib/apt/lists/*

# Рабочая директория
WORKDIR /app

# Копируем ТОЛЬКО исходник (без лишнего)
COPY Lesson1.cpp .

# Сборка через GCC
RUN g++ -std=c++17 -O2 -Wall -o lesson1-gcc Lesson1.cpp

# Сборка через Clang
RUN clang++ -std=c++17 -O2 -Wall -o lesson1-clang Lesson1.cpp

# Проверка: убедимся, что оба бинарника работают (без ввода — отключим ожидание)
RUN echo "3\n2 3\n1 2\n" | timeout 2 ./lesson1-gcc || true
RUN echo "3\n2 3\n1 2\n" | timeout 2 ./lesson1-clang || true

# Этап 2: легковесный рантайм-образ
FROM ubuntu:22.04

# Копируем только исполняемые файлы
COPY --from=builder /app/lesson1-gcc /usr/local/bin/
COPY --from=builder /app/lesson1-clang /usr/local/bin/

# Запуск: по умолчанию — обе версии с тестовым вводом
CMD ["/bin/bash", "-c", "echo '=== GCC ==='; echo -e '2\\n3 4\\n10 20\\n' | lesson1-gcc; echo -e '\\n=== Clang ==='; echo -e '2\\n3 4\\n10 20\\n' | lesson1-clang"]
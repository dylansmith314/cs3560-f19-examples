/**
 * @file source.cpp
 *
 * Based on https://github.com/yourWaifu/sleepy-discord/blob/master/examples/hello/example0.cpp
 * and https://github.com/yourWaifu/sleepy-discord/blob/master/examples/rock-paper-scissors/main.cpp
 */
#include <string>
#include <list>
#include "dotenv.h"
#include "sleepy_discord/sleepy_discord.h"

/**
 * @class MyBot
 * @brief An example bot
 *
 * It will response to message prefixed with ++, and add
 * reaaction to message.
 */
class MyBot : public SleepyDiscord::DiscordClient {
    private:
        struct CounterState {
            SleepyDiscord::User user;
            int count;

            CounterState(const SleepyDiscord::User& u) : user(u), count(0) {}
            CounterState(const CounterState& state) : user(state.user), count(state.count) {}
            ~CounterState() {}
        };
        std::list<CounterState> counter_states;
    public:
        using SleepyDiscord::DiscordClient::DiscordClient;
        void onMessage(SleepyDiscord::Message message) override {
            if (message.startsWith("++hello")) {
                sendMessage(message.channelID, "Hello " + message.author.username);
            } else if (message.startsWith("++incr")) {
                bool is_found = false;
                for (CounterState& state : counter_states) {
                    if (state.user == message.author) {
                        is_found = true;
                        state.count += 1;
                        // These do not work.
                        //std::string emoji = u8"\U0001F44D";
                        //std::string emoji = "\xE8\xAA\x9E";
                        //std::string emoji = "\U0001F534";
                        //std::string emoji = "\U0001F534";

                        // "The emoji must be URL Encoded or the request will fail with 10014: Unknown Emoji."
                        // from https://discord.com/developers/docs/resources/channel#create-reaction
                        // Conversion from https://r12a.github.io/app-conversion/
                        std::string emoji = "%F0%9F%91%8D"; // 👍
                        addReaction(message.channelID, message.ID, emoji);
                    }
                }
                if (!is_found) {
                    std::cout << "Creating state for " + message.author.username + "\n";
                    CounterState s(message.author);
                    s.count += 1;
                    counter_states.push_back(s);

                    std::string emoji = "%F0%9F%91%8D"; // 👍
                    addReaction(message.channelID, message.ID, emoji);
                }
            } else if (message.startsWith("++val")) {
                bool is_found = false;
                for (CounterState& state : counter_states) {
                    if (state.user == message.author) {
                        is_found = true;
                        message.reply(this, "value: " + std::to_string(state.count));
                    }
                }
                if (!is_found) {
                    message.reply(this, "nothing");
                }
            }
        }
};

int main() {
    dotenv::env.load_dotenv();
    MyBot bot(dotenv::env["DISCORD_BOT_TOKEN"], SleepyDiscord::USER_CONTROLED_THREADS);
    bot.setIntents(SleepyDiscord::Intent::SERVER_MESSAGES | SleepyDiscord::Intent::SERVER_EMOJIS | SleepyDiscord::Intent::SERVER_MESSAGE_REACTIONS );
    bot.run();
}

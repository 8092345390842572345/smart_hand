# I don't know what's the hell is that and how it works but 
# if you have questions it's my email:
#   --------------------------
#   | ashtl.f1ra5h@gmail.com |
#   --------------------------

import os
from x import LiveSpeech, get_model_path

model_path = get_model_path()

speech = LiveSpeech(
    verbose=False,
    sampling_rate=16000,
    buffer_size=2048,
    no_search=False,
    full_utt=False,
    hmm=os.path.join(model_path, 'zero_ru.cd_cont_4000'),
    lm=os.path.join(model_path, 'ru.lm'),
    dic=os.path.join(model_path, 'ru.dic')
)

print("Say something!")

for phrase in speech:
    print(phrase)
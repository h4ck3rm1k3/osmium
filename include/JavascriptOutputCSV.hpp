#ifndef OSMIUM_OUTPUT_CSV_HPP
#define OSMIUM_OUTPUT_CSV_HPP

#include <fstream>

namespace Osmium {

    namespace Output {

        class CSV {

          public:

            std::ofstream out;

            v8::Persistent<v8::Object> js_object;

            CSV(const char *filename) {
                out.open(filename);
                js_object = v8::Persistent<v8::Object>::New( Osmium::Javascript::Template::create_output_csv_instance(this) );
            }

            ~CSV() {
                out.flush();
                out.close();
            }

            v8::Handle<v8::Object> get_js_object() const {
                return js_object;
            }

        }; // class CSV

    } // namespace Output

} // namespace Osmium

#endif // OSMIUM_OUTPUT_CSV_HPP

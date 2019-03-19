FROM vvakame/review:3.1

RUN apt-get -y update || true
RUN apt-get -y upgrade && \
	apt-get -y update && \
	apt-get -y install build-essential zlib1g-dev libxslt1-dev libxml2 libxml2-dev ruby-dev libgconf-2-4 wget unzip curl procps


WORKDIR /vivliostyle

ARG VIVLIOSTYLE_VERSION
RUN rm -rf /usr/local/bin/vivliostyle-server
RUN wget https://github.com/vivliostyle/vivliostyle.js/releases/download/${VIVLIOSTYLE_VERSION}/vivliostyle-js-${VIVLIOSTYLE_VERSION}.zip
RUN unzip vivliostyle-js-${VIVLIOSTYLE_VERSION}.zip
RUN cp ./vivliostyle-js-${VIVLIOSTYLE_VERSION}/start-webserver /usr/local/bin/vivliostyle-server
RUN rm -rf vivliostyle-js-${VIVLIOSTYLE_VERSION}.zip


WORKDIR /repository_root

RUN npm install -g n
RUN n v11.6.0
RUN npm i -g npm@6.6.0

# Install latest chrome dev package and fonts to support major charsets (Chinese, Japanese, Arabic, Hebrew, Thai and a few others)
# Note: this installs the necessary libs to make the bundled version of Chromium that Puppeteer
# installs, work.
RUN apt-get update && apt-get install -y wget --no-install-recommends \
	&& wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | apt-key add - \
	&& sh -c 'echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" >> /etc/apt/sources.list.d/google.list' \
	&& apt-get update \
	&& apt-get install -y google-chrome-unstable fonts-ipafont-gothic fonts-wqy-zenhei fonts-thai-tlwg fonts-kacst ttf-freefont \
	--no-install-recommends \
	&& rm -rf /var/lib/apt/lists/* \
	&& apt-get purge --auto-remove -y curl \
	&& rm -rf /src/*.deb

# It's a good idea to use dumb-init to help prevent zombie chrome processes.
ADD https://github.com/Yelp/dumb-init/releases/download/v1.2.0/dumb-init_1.2.0_amd64 /usr/local/bin/dumb-init
RUN chmod +x /usr/local/bin/dumb-init

# Uncomment to skip the chromium download when installing puppeteer. If you do,
# you'll need to launch puppeteer with:
#     browser.launch({executablePath: 'google-chrome-unstable'})
# ENV PUPPETEER_SKIP_CHROMIUM_DOWNLOAD true

RUN rm -rf /etc/apt/sources.list.d/google.list && apt-get update && apt-get -qq -y install curl

# fonts
RUN apt-get install -y fonts-ipa* fonts-ricty-diminished

# java
RUN mkdir -p /usr/share/man/man1 && apt-get install -y default-jre

COPY startup.sh /startup.sh
RUN chmod +x /startup.sh

ENTRYPOINT [ "/startup.sh" ]

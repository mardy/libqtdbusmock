/*
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Pete Woods <pete.woods@canonical.com>
 */

#include <config.h>

#include <QCoreApplication>
#include <gtest/gtest.h>

#include <libqtdbusmock/DBusMock.h>

using namespace QtDBusMock;

int main(int argc, char **argv) {
	qputenv("LANG", "C.UTF-8");
	unsetenv("LC_ALL");

	setlocale(LC_ALL, "");
	bindtextdomain(GETTEXT_PACKAGE, LOCALE_DIR);
	textdomain(GETTEXT_PACKAGE);

	QCoreApplication application(argc, argv);

	DBusMock::registerMetaTypes();

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
